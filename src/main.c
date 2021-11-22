/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:18:10 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/22 12:41:11 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "../fractol.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

int	mousehook(int mouse, int x, int y, t_var *var)
{
	if (mouse == 4)
		zoom(x, y, var, 1);
	if (mouse == 5)
		zoom(x, y, var, -1);
	return (0);
}

int	keyhook(int key, t_var *var)
{
	if (key == 126)
		move(var, 0, -1 * var->fractal.ytotal / 20);
	if (key == 125)
		move(var, 0, var->fractal.ytotal / 20);
	if (key == 123)
		move(var, -1 * var->fractal.xtotal / 20, 0);
	if (key == 124)
		move(var, var->fractal.xtotal / 20, 0);
	if (key == 49)
		change_color(var);
	if (key == 15)
		reset_axis(var);
	if (key == 53)
		exit(0);
	return (0);
}

void	error_usage(int error)
{
	if (error == 0)
	{
		printf("Usage: ./fractol [mandelbrot] [julia] ");
		printf("[mandelbar] [buffalo] [burningship] [eperaita]");
	}
	else if (error == 1)
	{
		printf("	Usage example: ./fractol julia [0] [0.8]\n");
		printf("		(Parameters must be doubles from 0 to 2)");
	}
	exit (0);
}

void	ft_choose_fractal(t_var *var, int first)
{
	if (ft_strcmp(var->fractal.args[1], "mandelbrot"))
		ft_mandelbrot(var, first);
	else if (ft_strcmp(var->fractal.args[1], "mandelbar"))
		ft_manbar_buff_ship(var, first, 0);
	else if (ft_strcmp(var->fractal.args[1], "buffalo"))
		ft_manbar_buff_ship(var, first, 1);
	else if (ft_strcmp(var->fractal.args[1], "burningship"))
		ft_manbar_buff_ship(var, first, 2);
	else if (ft_strcmp(var->fractal.args[1], "eperaita"))
		ft_eperaita(var, first);
	else if (ft_strcmp(var->fractal.args[1], "julia"))
	{
		if (!var->fractal.args[2] || !var->fractal.args[3]
			|| ft_atoi(var->fractal.args[2]) > 2
			|| ft_atoi(var->fractal.args[3]) > 2)
			error_usage(1);
		else
			ft_julia(var, ft_atoi_double(var->fractal.args[2]),
				ft_atoi_double(var->fractal.args[3]), first);
	}
	else
		error_usage(0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc < 2)
		error_usage(0);
	set_mlx(&var);
	set_img(&var);
	var.fractal.args = argv;
	var.fractal.ncolor = 0;
	ft_choose_fractal(&var, 0);
	mlx_key_hook(var.win, keyhook, &var);
	mlx_mouse_hook(var.win, mousehook, &var);
	free(var.img.color);
	mlx_loop(var.mlx);
	return (0);
}
