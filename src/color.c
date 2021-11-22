/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:00:33 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/22 12:35:26 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdlib.h>

/////////////////OPTIONS OF COLOR/////////////
//     Change the options using Space      //

// 0 = Palette: 
// 		Manual color palette. 
// 		Default palette: "Solinis Pastel" 
// 1 = Scaled: 
// 		Manual color palette + number of iterations 
// 		(more scales)
// 2 = Toned: 
// 		Color + iterations
// 		(you can change it by setting starting color in hexa)
// 3 = Iteration: 
// 		Starting from 0 represents number of iterations 
// 		(thats why is so blue)
// 4 = Insanity: 
// 		Random colors based on color palette + i * 10 
// 		(even if you zoom or move, it change) 
// 		(adds too much numbers to the default int)

/////////////////////////////////////////////

void	put_color(t_var *var, int x, int y)
{
	if (var->fractal.ncolor == 0)
		var->img.add[y * var->img.w + x]
			= var->img.color[(var->fractal.i) / 10];
	else if (var->fractal.ncolor == 1)
		var->img.add[y * var->img.w + x]
			= var->img.color[(var->fractal.i) / 10] + var->fractal.i * 100;
	else if (var->fractal.ncolor == 2)
		var->img.add[y * var->img.w + x]
			= 0x67074e + (var->fractal.i * 10);
	else if (var->fractal.ncolor == 3)
		var->img.add[y * var->img.w + x]
			= (var->fractal.i * 10);
	else if (var->fractal.ncolor == 4)
		var->img.add[y * var->img.w + x]
			= var->img.color[(var->fractal.i)] + (var->fractal.i * 10000);
}

void	set0(t_var *var)
{
	var->img.color[0] = 0x92a8d1;
	var->img.color[1] = 0xabb1cf;
	var->img.color[2] = 0xc5b9cd;
	var->img.color[3] = 0xdec2cb;
	var->img.color[4] = 0xf7cac9;
	var->img.color[5] = 0x92a8d1;
	var->img.color[6] = 0xabb1cf;
	var->img.color[7] = 0xc5b9cd;
	var->img.color[8] = 0xdec2cb;
	var->img.color[9] = 0xf7cac9;
	var->img.color[10] = 0x000000;
}

void	set1(t_var *var)
{
	var->img.color[0] = 0xde9933;
	var->img.color[1] = 0xf89e18;
	var->img.color[2] = 0xc82455;
	var->img.color[3] = 0x000000;
	var->img.color[4] = 0x6214ad;
	var->img.color[5] = 0x9618b4;
	var->img.color[6] = 0xba1ca9;
	var->img.color[7] = 0xc82455;
	var->img.color[8] = 0xcf2a29;
	var->img.color[9] = 0xdd9933;
	var->img.color[10] = 0x000000;
}

void	set4(t_var *var)
{
	var->img.color[0] = 0xde9933;
	var->img.color[1] = 0xf89e18;
	var->img.color[2] = 0xc82455;
	var->img.color[3] = 0x000000;
	var->img.color[4] = 0x6214ad;
	var->img.color[5] = 0x9618b4;
	var->img.color[6] = 0xba1ca9;
	var->img.color[7] = 0xc82455;
	var->img.color[8] = 0xcf2a29;
	var->img.color[9] = 0xdd9933;
	var->img.color[10] = 0x000000;
}

void	set_color(t_var *var)
{
	var->img.color = (int *)malloc(sizeof (int) * 11);
	if (!var->img.color)
		exit (0);
	if (var->fractal.ncolor == 0)
		set0(var);
	if (var->fractal.ncolor == 1)
		set1(var);
	if (var->fractal.ncolor == 4)
		set4(var);
}
