/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:00:33 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 13:39:55 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdlib.h>

void set_color(t_var *var)
{
    var->img.color = (int *)malloc(sizeof (int) * 11);
    
	/*var->img.color[0] =0xbcdd5e;
	var->img.color[1] =0x23bb13;
    var->img.color[2] =0x2aaf9d;
    var->img.color[3] =0x2facb0;
    var->img.color[4] =0x7f197f;
    var->img.color[5] =0x4e1f46;
    var->img.color[6] =0x72d289;
    var->img.color[7] =0xce3481;
    var->img.color[8] =0xd6df4c;
	var->img.color[9] =0x573c9e;
    var->img.color[10] =0x2f1c3d;*/
	
	
	var->img.color[0] =0x92a8d1;
    var->img.color[1] =0xabb1cf;
    var->img.color[2] =0xc5b9cd;
    var->img.color[3] =0xdec2cb;
    var->img.color[4] =0xf7cac9;
    var->img.color[5] =0x92a8d1;
    var->img.color[6] =0xabb1cf;
    var->img.color[7] =0xc5b9cd;
    var->img.color[8] =0xdec2cb;
    var->img.color[9] =0xf7cac9;
    var->img.color[10] =0x000000;
}
