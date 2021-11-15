/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:54:43 by eperaita          #+#    #+#             */
/*   Updated: 2021/11/15 23:45:05 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>

int check_scape(t_coo *coo)
{
    double scape;

    scape = sqrt(pow(coo->zy, 2) + pow(coo->zx, 2));
    if (scape > 25)
        return (1);
    return (0);
}

void	set_axis(t_coo *coo)
{
	coo->xmax = 2;
   	coo->xmin = -2;
   	coo->ymax = 2;
   	coo->ymin = -2;
   	coo->xtotal = coo->xmax + (coo->xmin * -1);
	coo->ytotal = coo->ymax + (coo->ymin * -1);
}

