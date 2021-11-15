/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/16 00:18:36 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"
#include "../mlx/mlx.h"


///La idea de aplicar reiteradamente una funcion sobre un valor (mandelbrot y julia)
//Se aplica aqui con funcion reursiva (misma idea en la que llamamos a la misma fncion alterando el valor cada iteración)
//Plus_constant se llama a si misma sumando  el valor de la constante en cada iteracion. Se reutiliza la funcion para los dos fractales porque las variabes ya estan asignadas a cual es constante y cual es z. 

void plus_constant(double zx, double zy, t_coo *coo)
{
	coo->i++;
    if (sqrt(pow(zx, 2) + pow(zy, 2)) > 25)
        return; 
    if (coo->i < 100)
		plus_constant(pow(zx, 2) - pow(zy, 2) + coo->cx, (2 * zx * zy) + coo->cy, coo);
}

////Check diverge escala cada coordenada a valores proporcionados al rango, dependiendo de que conjunto sea, los setea en el valor constante o en el valor z.
//LLama a la recursiva y luego pinta pixel

void check_diverge(int x, int y, t_coo *coo, t_var *var, int fr)
{
	coo->i  = 0;
	if (fr == 0)
	{
		coo->cx = (-1 * (-1 * coo->xmin) + ((double)x / (double)var->img.w) * coo->xtotal);
		coo->cy = (-1) * ((-1 * coo->ymin) - ((double)y / (double)var->img.h) * coo->ytotal); //si quitas el -1 tambien funciona!!! y julia no, espejo
	}
	else if (fr == 1)
	{
		coo->zx = (-1 * (-1 * coo->xmin)) + ((double)x / (double)var->img.w) * (coo->xtotal);
  		coo->zy = (-1) * ((-1 * coo->ymin) - ((double)y / (double)var->img.h) * (coo->ytotal));	
	}
	plus_constant(coo->zx, coo->zy, coo);
	var->img.add[y * var->img.w + x] = var->img.color[(coo->i)/10];
}

/////Cada funcion (mandelbrot o julia) establece sus parametros , comienza el bucle de iterar la matriz y manda coordenadas a check_diverge.

t_coo ft_mandelbrot(t_var *var, int first)
{
    t_coo man;
    int y;
    int x;

	if (!first)
		set_axis(&man);
	y = 0;
    while (y < var->img.h)
    {
        x = 0;
        while (x < var->img.w)
        {
            check_diverge(x, y, &man, var, 0);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	return (man);
}

t_coo ft_julia(t_var *var, double cx, double cy, int first)
{
    t_coo jul;
    int y;
    int x;

    jul.cx = cx;
    jul.cy = cy;
	if (!first)
    	set_axis(&jul);
    y = 0;
    while (y < var->img.h)
    {
        x = 0;
        while (x++ < var->img.w)
            check_diverge(x, y, &jul, var, 1);
        y++;
    }
    mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	return (jul);
}
