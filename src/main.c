/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:18:10 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 23:50:21 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

int keyhook(int key, t_var *var, char **argv)
{
    printf("%d\n", key);
	if (key == 126)
		axis_move(var, argv, 0, -1);
	if (key == 125)
		axis_move(var, argv, 0, 1);
	if (key == 123)
		axis_move(var, argv, -1, 0);
	if (key == 124)
		axis_move(var, argv, 1, 0);
	if (key == 53)
	{
		//free_todo
		exit(0);
	}
	return (0);
}

void error_usage(void)
{
    perror("Usage : ./fractol [mandelbrot] [julia] [...]");//como se usa? que escribo?
    exit (0);
}

void	set_img(t_var *var)
{
    var->img.img = mlx_new_image(var->mlx, 600, 600);
    var->img.add = (int *)mlx_get_data_addr(var->img.img, &var->img.bpp, &var->img.w, &var->img.endian);
    set_color(var);
    var->img.w = 600;
    var->img.h = 600;
}

void set_mlx(t_var *var)
{
	var->mlx = mlx_init();
    var->win = mlx_new_window(var->mlx, 600, 600, "Fractol");//iniciar ventana despues de elegir fractal?
	//inicializar variables??
}

void ft_choose_fractal(char **argv, t_var *var, int first)
{
	if (ft_strcmp(argv[1], "mandelbrot"))
		var->fractal = ft_mandelbrot(var, first);
	else if (ft_strcmp(argv[1], "julia"))
		var->fractal = ft_julia(var, ft_atoi_double(argv[2]),ft_atoi_double(argv[3]), first); //  gstion de errores + args
	else
		error_usage();
}

int main (int argc, char **argv)
{
	t_var   var;

    if (argc < 2)
        error_usage();
    set_mlx(&var);
	set_img(&var);
    ft_choose_fractal(argv, &var, 0);
	(void)argv;
	///////HOOKS//////
	mlx_hook(var.win, 2, 1L<<0, keyhook, &var); //hook TECLA
	/////////////////
	free(var.img.color);//liberar todo
    mlx_loop(var.mlx);
    return (0);	
}
