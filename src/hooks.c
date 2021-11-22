/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:23:19 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/19 12:07:13 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fractol.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	axis_move(t_var *var, double xmove, double ymove)
{
	if (xmove)
	{
		var->fractal.xmax += xmove;
		var->fractal.xmin += xmove;
		var->fractal.xtotal = var->fractal.xmax + (var->fractal.xmin * -1);
	}
	if (ymove)
	{
		var->fractal.ymax -= ymove;
		var->fractal.ymin -= ymove;
		var->fractal.ytotal = var->fractal.ymax + (var->fractal.ymin * -1);
	}
}

void	zoom(double x, double y, t_var *var, int zoom)
{
	double	mousex;
	double	mousey;
	double	neg;

	neg = 1.0;
	mlx_clear_window(var->mlx, var->win);
	mousex = (-1 * (-1 * var->fractal.xmin)
			+ ((double)x / (double)var->img.w) * var->fractal.xtotal);
	mousey = ((-1 * var->fractal.ymin)
			- ((double)y / (double)var->img.h) * var->fractal.ytotal);
	axis_move(var, ((mousex) / (var->fractal.xtotal / 2))
		* (var->fractal.xtotal / 20), (((mousey) / (var->fractal.ytotal / 2)))
		* (var->fractal.ytotal / 20));
	if (zoom < 0)
		neg = -1.0;
	var->fractal.ymax += var->fractal.ytotal / 20 * neg;
	var->fractal.ymin -= var->fractal.ytotal / 20 * neg;
	var->fractal.xmax += var->fractal.xtotal / 20 * neg;
	var->fractal.xmin -= var->fractal.xtotal / 20 * neg;
	var->fractal.xtotal = var->fractal.xmax + (var->fractal.xmin * -1);
	var->fractal.ytotal = var->fractal.ymax + (var->fractal.ymin * -1);
	set_img(var);
	ft_choose_fractal(var, 1);
}

void	move(t_var *var, double xmove, double ymove)
{
	mlx_clear_window(var->mlx, var->win);
	axis_move(var, xmove, ymove);
	set_img(var);
	ft_choose_fractal(var, 1);
}

void	change_color(t_var *var)
{
	mlx_clear_window(var->mlx, var->win);
	free(var->img.color);
	if (var->fractal.ncolor < 4)
		var->fractal.ncolor++;
	else
		var->fractal.ncolor = 0;
	set_img(var);
	ft_choose_fractal(var, 1);
}

void	reset_axis(t_var *var)
{
	mlx_clear_window(var->mlx, var->win);
	set_axis(&var->fractal);
	set_img(var);
	ft_choose_fractal(var, 1);
}
