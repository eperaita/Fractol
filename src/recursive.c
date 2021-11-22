/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/22 12:25:36 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fractol.h"
#include "../mlx/mlx.h"

void	plus_constant(double zx, double zy, t_coo *fractal)
{
	fractal->i++;
	if (sqrt(pow(zx, 2) + pow(zy, 2)) > 25)
		return ;
	if (fractal->i < 100)
		plus_constant(pow(zx, 2) - pow(zy, 2)
			+ fractal->cx, (2 * zx * zy) + fractal->cy, fractal);
}

void	check_diverge(int x, int y, t_var *var, int fr)
{
	var->fractal.i = 0;
	if (fr == 0)
	{
		var->fractal.cx = (-1 * (-1 * var->fractal.xmin)
				+ ((double)x / (double)var->img.w) * var->fractal.xtotal);
		var->fractal.cy = (-1) * ((-1 * var->fractal.ymin)
				- ((double)y / (double)var->img.h) * var->fractal.ytotal);
	}
	else if (fr == 1)
	{
		var->fractal.zx = (-1 * (-1 * var->fractal.xmin))
			+ ((double)x / (double)var->img.w) * (var->fractal.xtotal);
		var->fractal.zy = (-1) * ((-1 * var->fractal.ymin)
				- ((double)y / (double)var->img.h) * (var->fractal.ytotal));
	}
	plus_constant(var->fractal.zx, var->fractal.zy, &var->fractal);
	put_color(var, x, y);
}

void	ft_mandelbrot(t_var *var, int first)
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
			check_diverge(x, y, var, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

void	ft_julia(t_var *var, double cx, double cy, int first)
{
	int	y;
	int	x;

	if (!cx && !cy)
	{
		cx = 0;
		cy = 0.8;
	}
	var->fractal.cx = cx;
	var->fractal.cy = cy;
	if (!first)
		set_axis(&var->fractal);
	y = 0;
	while (y < var->img.h)
	{
		x = 0;
		while (x++ < var->img.w)
			check_diverge(x, y, var, 1);
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
