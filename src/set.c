/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:54:43 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/22 11:34:33 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../mlx/mlx.h"

void	set_axis(t_coo *fractal)
{
	fractal->xmax = 2;
	fractal->xmin = -2;
	fractal->ymax = 2;
	fractal->ymin = -2;
	fractal->xtotal = fractal->xmax + (fractal->xmin * -1);
	fractal->ytotal = fractal->ymax + (fractal->ymin * -1);
}

void	set_img(t_var *var)
{
	var->img.img = mlx_new_image(var->mlx, 600, 600);
	var->img.add = (int *)mlx_get_data_addr(var->img.img,
			&var->img.bpp, &var->img.w, &var->img.endian);
	set_color(var);
	var->img.w = 600;
	var->img.h = 600;
}

void	set_mlx(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 600, 600, "Fractol");
}
