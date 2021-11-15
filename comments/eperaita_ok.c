/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eperaita_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:36:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 17:00:29 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../fractol.h"
#include "../mlx/mlx.h"

int check_scape(t_coo *epe)
{
    double scape;

    scape = sqrt(pow(epe->zy, 2) + pow(epe->zx, 2));
    if (scape < epe->max / 2)
        return (1);
    return (2);
}

void check_diverge(int x, int y, t_coo *epe, t_var *var)
{
    int i;
    double scape;

    i = 0;
	epe->zx  = 0;
	epe->zy  = 0;
    epe->cx = (-1 * (epe->max/ 2)) + ((double)x / (double)var->img.w) * epe->max;
    epe->cy = (epe->max / 2) - ((double)y / (double)var->img.h) * epe->max;
    while ( i < 100)
    {
		/////////Cuando cambia la zx la utiliza para aplicar la 2ºformula a la zy, por lo que zy(n+1) sera z(n+2)///////
        epe->zx = (pow(epe->zx, 2) - pow(epe->zy, 2)) + epe->cx;
       	epe->zy = ((2 * epe->zx * epe->zy)) + epe->cy;
       /* epe->kx = pow(epe->zx, 2) - pow(epe->zy, 2); //Sustituye a esto, que opera la x, y a la par
        epe->ky = (2 * epe->zx * epe->zy);
		epe->zx = epe->kx + epe->cx;
		epe->zy = epe->ky + epe->cy;*/
    	scape = sqrt(pow(epe->zy, 2) + pow(epe->zx, 2));
    	if (scape > 25)
			break ;
        i++;
    }
    var->img.add[y * var->img.w + x] = var->img.color[i/10];
}

void ft_eperaita(t_var *var)
{
    t_coo epe;
    int y;
    int x;

    epe.max = 4;
	y = 0;
    while (y < var->img.h)
    {
        x = 0;
        while (x < var->img.w)
        {
            check_diverge(x, y, &epe, var);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

