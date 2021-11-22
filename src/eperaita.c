/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eperaita.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/18 22:04:29 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"
#include "../mlx/mlx.h"

//Due to an error, the program to print Mandelbrot set turned into a 
//new fractal now named eperaita. The way to get the values of each point 
//is to apply a function recursively (as in Mandelbrot set),but the value 
//modified in zx(n) is used to get zy(n). 
//Therefor, the zy(n) in Mandelbrot is zy(n+1) in eperaita but zx(n) in both. 
//(Line 47)

void	check_diverge_eperaita(int x, int y, t_var *var)
{
	double	scape;

	var->fractal.i = 0;
	var->fractal.zx = 0;
	var->fractal.zy = 0;
	var->fractal.cx = (-1 * (var->fractal.xtotal / 2))
		+ ((double)x / (double)var->img.w) * var->fractal.xtotal;
	var->fractal.cy = (var->fractal.ytotal / 2)
		- ((double)y / (double)var->img.h) * var->fractal.ytotal;
	while (var->fractal.i < 100)
	{
		var->fractal.zx = (pow(var->fractal.zx, 2)
				- pow(var->fractal.zy, 2)) + var->fractal.cx;
		var->fractal.zy = ((2 * var->fractal.zx
					* var->fractal.zy)) + var->fractal.cy;
		scape = sqrt(pow(var->fractal.zy, 2) + pow(var->fractal.zx, 2));
		if (scape > 25)
			break ;
		var->fractal.i++;
	}
	put_color(var, x, y);
}

void	ft_eperaita(t_var *var, int first)
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
			check_diverge_eperaita(x, y, var);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
