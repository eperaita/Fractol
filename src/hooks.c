/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:54:21 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 23:50:52 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void axis_move(t_var *var, char **argv, double xmove, double ymove)
{
	if (xmove != 0)//(xmax + xmove) y (xmin + xmove)
	{
		var->fractal.xmax += xmove;
		var->fractal.xmin += xmove;
	}
	if(ymove != 0)//(ymax + ymove) y (ymin + ymove)
	{
		var->fractal.ymax += ymove;
		var->fractal.ymax += ymove;
	}
	//tego que destruir la imagen (no destroy window) y generar otra 
	//free()
	ft_choose_fractal(argv, var, 1);
	///llamo aqui a choose_fractal, vuelvo a llamar a julia o a mandel....necesito saber cuall es, con el argv[1] o guardarlo en la struct
	//ademas necesito saber si es la primera vez para setear axis o no
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

