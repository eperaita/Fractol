/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 16:56:44 by eperaita         ###   ########.fr       */
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

void check_diverge(int x, int y, t_coo *man, t_var *var)
{
    int i;
    double scape;

    i = 0;
	man->zx  = 0;
	man->zy  = 0;
    man->cx = (-1 * (man->max/ 2)) + ((double)x / (double)var->img.w) * man->max;
    man->cy = (man->max / 2) - ((double)y / (double)var->img.h) * man->max;
    while ( i < 100) 
    {
        man->kx = pow(man->zx, 2) - pow(man->zy, 2);
        man->ky = (2 * man->zx * man->zy);
		man->zx = man->kx + man->cx;
		man->zy = man->ky + man->cy;
    	if (check_scape)
			break ;
        i++;
    }
    var->img.add[y * var->img.w + x] = var->img.color[i/10]; // Asigna un int (como puntero a hexadecimal) en el address que representa un color. 
}
//zx y zy empiezan en 0 (valor que se modifica en cada iteracion)
//Cada coordenada (x, y) se asigna a constante (cx, cy), se escala al valor del eje
//Itera 100 veces para ver en que iteracion de la suma de la formula cuadratica reiterada escapa del valor maximo
//en cada iteracion comprueba si escapa al max (check_scape()) y si no escapa suma la constante (cx, cy) (coordenada en mandelbrot)
//cuando escapa, el valor de la i es el numer de iteracion en el que ocurre, por lo que determina un color en la escala de colores asignada


void ft_mandelbrot(t_var *var)
{
    t_coo man;
    int y;
    int x;

    man.max = 4;
	y = 0;
    while (y < var->img.h)
    {
        x = 0;
        while (x < var->img.w)
        {
            check_diverge(x, y, &man, var);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
//Declaracion de estructura man, asignar valor maximo de eje
//Bucle de iteracion en la img con x,y. se manda cada coordenada a check_diverge.
//Put image

