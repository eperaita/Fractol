/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_buff_ship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/22 12:47:02 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"
#include "../mlx/mlx.h"

void	buffalo(t_var *var)
{
	double	kx;

	var->fractal.zy = fabs(var->fractal.zy);
	kx = pow(var->fractal.zx, 2) - pow(var->fractal.zy, 2);
	var->fractal.zy = (2 * var->fractal.zx * var->fractal.zy) + var->fractal.cy;
	var->fractal.zx = kx + var->fractal.cx;
}

void	burning_ship(t_var *var)
{
	double	kx;

	var->fractal.zx = fabs(var->fractal.zx);
	var->fractal.zy = fabs(var->fractal.zy);
	kx = pow(var->fractal.zx, 2) - pow(var->fractal.zy, 2);
	var->fractal.zy = (2 * var->fractal.zx * var->fractal.zy) + var->fractal.cy;
	var->fractal.zx = kx + var->fractal.cx;
}

void	mandelbar(t_var *var)
{
	double	kx;

	kx = pow(var->fractal.zx, 2) - pow(var->fractal.zy, 2);
	var->fractal.zy = (-1 *(2 * var->fractal.zx * var->fractal.zy
				+ var->fractal.cy));
	var->fractal.zx = kx + var->fractal.cx;
}

void	set_iter(int x, int y, t_var *var, int fractal)
{
	var->fractal.i = 0;
	var->fractal.zx = 0.0;
	var->fractal.zy = 0.0;
	var->fractal.cx = (-1 * (-1 * var->fractal.xmin) + ((double)x
				/ (double)var->img.w) * var->fractal.xtotal);
	var->fractal.cy = (-1) * ((-1 * var->fractal.ymin) - ((double)y
				/ (double)var->img.h) * var->fractal.ytotal);
	while (var->fractal.i < 250)
	{
		if (fractal == 0)
			mandelbar(var);
		if (fractal == 1)
			buffalo(var);
		if (fractal == 2)
			burning_ship(var);
		if (sqrt(pow(var->fractal.zy, 2) + pow(var->fractal.zx, 2)) > 25)
			break ;
		var->fractal.i++;
	}
	put_color(var, x, y);
}

void	ft_manbar_buff_ship(t_var *var, int first, int fractal)
{
	int	y;
	int	x;

	if (!first)
		set_axis(&var->fractal);
	y = 0;
	while (y < var->img.h)
	{
		x = 0;
		while (x < var->img.w)
		{
			set_iter(x, y, var, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
