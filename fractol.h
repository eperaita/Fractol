/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:40:43 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 23:49:47 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

typedef struct  s_coo {
    double	cx;
    double	cy;
    double	zx;
	double	zy;
	int		i;
	double	xmax;
	double	ymax;
	double	xmin;
	double	ymin;
	double	xtotal;
	double	ytotal;
}               t_coo;

typedef struct  s_data {
    void    *img;
	int		*add;
    int     bpp;
	int     endian;
    int     w;
    int     h;
	int		*color;
}               t_data;

typedef struct  s_var {
    void    *mlx;
    void    *win;
    t_data  img;
    t_coo	fractal;
}               t_var;

t_coo	ft_mandelbrot(t_var *var, int first);
t_coo	ft_julia(t_var *var, double cx, double cy, int first);
void ft_choose_fractal(char **argv, t_var *var, int first);

////UTILS////
int		check_scape(t_coo *coo);
void    set_axis(t_coo *coo);

////COLOR////
void	set_color(t_var *var);

////HOOKS///
void axis_move(t_var *var, char **argv, double xmove, double ymove);

#endif
