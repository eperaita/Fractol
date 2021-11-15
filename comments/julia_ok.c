/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_ok.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 17:31:40 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"
#include "../mlx/mlx.h"

int check_scape(t_coo *man)
{
    double scape;

    scape = sqrt(pow(man->zy, 2) + pow(man->zx, 2));
    if (scape > man->max / 2)
        return (1);
    return (0);
}

void check_diverge_jul(int x, int y, t_coo *jul, t_var *var)
{
    int i;

    i = 0;
    jul->zx = (-1 * (jul->max/ 2)) + ((double)x / (double)var->img.w) * jul->max;
    jul->zy = (-1) * ((jul->max / 2) - ((double)y / (double)var->img.h) * jul->max);//por que * -1???
    while ( i < 100)
    {
        jul->kx = pow(jul->zx, 2) - pow(jul->zy, 2);
        jul->ky = (2 * jul->zx * jul->zy);
		jul->zx = jul->kx + jul->cx;
		jul->zy = jul->ky + jul->cy;
    	if (check_scape(jul))
			break ;
        i++;
    }
    var->img.add[y * var->img.w + x] = var->img.color[i/10]; // Asigna un int (como puntero a hexadecimal) en el address que representa un color.
}
//zx y zy en este caso son la coordenada (valor que se modifica en cada iteracion)
//La constante es la que va a sumarse, y son los parametros ya guardados en struct
//Itera 100 veces para ver en que iteracion de la suma de la formula cuadratica reiterada escapa del valor maximo
//en cada iteracion comprueba si escapa al max (check_scape()) y si no escapa suma la constante (cx, cy) (parametros en julia)
//cuando escapa, el valor de la i es el numer de iteracion en el que ocurre, por lo que determina un color en la escala de colores asignada


void ft_julia(t_var *var, double cx, double cy)
{
    t_coo jul;
    int y;
    int x;

	jul.cx = cx;
	jul.cy = cy;
    jul.max = 4;
	y = 0;
    while (y < var->img.h)
    {
        x = 0;
        while (x++ < var->img.w)
            check_diverge_jul(x, y, &jul, var);
        y++;
    }
    mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
//Declaracion de estructura man, asignar valor maximo de eje
//En Juia, se asigna a constante (cx, cy) los parametros del input
//Bucle de iteracion en la img con x,y. se manda cada coordenada a check_diverge.
//Put image
