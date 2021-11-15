/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 23:48:43 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"
#include "../mlx/mlx.h"


void plus_constant(double zx, double zy, t_coo *coo)
{
	coo->i++;
    if (sqrt(pow(zx, 2) + pow(zy, 2)) > 25)
        return; 
    if (coo->i < 100)
		plus_constant(pow(zx, 2) - pow(zy, 2) + coo->cx, (2 * zx * zy) + coo->cy, coo);
}

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
