/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:00:39 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/10 13:24:43 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	raycast(char *map, t_data *d, t_pos p)
{
	int		x;
	double	dw;

	dw = d->wiwdth;
	x = -1;
	while (++x < d->width)
	{
		p.camx = 2 * x / dw - 1;
		p.rayposx = p.posx;
		p.rayposy = p.posy;
		p.raydirx = p.dirx + p.planex * p.camx;
		p.raydiry = p.diry + p.planey * p.camx;
		p.mapx = int(p.rayposx);
		p.mapx = int(p.rayposx);
		p.stepx = p.raydirx > 0 ? 1 : -1;
		p.stepx = p.raydiry > 0 ? 1 : -1;
	}
}
