/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:10:29 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:01:34 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	update_spd(t_data *d)
{
	double	move;

	move = d->keycodes[W] + d->keycodes[S];
	d->spdx = d->keycodes[A] + d->keycodes[D];
	if (d->spdy != 0 && move != 0)
	{
		d->spdy *= 1.1;
		if (d->spdy < 0 && move < 0 && d->spdy < -MAXSPEED)
			d->spdy = -MAXSPEED;
		if (d->spdy > 0 && move > 0 && d->spdy > MAXSPEED)
			d->spdy = MAXSPEED;
	}
	else
		d->spdy = move;
	if (d->spdy != 0)
		d->spdy = d->spdy > 0 ? d->spdy + d->sprint : d->spdy - d->sprint;
}

void	move(t_data *d, double dirx, double diry)
{
	double	tmp;

	if (d->map[(int)(d->posx + dirx)][(int)(d->posy + diry)] != 1)
	{
		d->posx += dirx;
		d->posy += diry;
	}
	if (d->spdx > 0)
	{
		tmp = d->dirx;
		d->dirx = d->dirx * cos(-d->rotspd) - d->diry * sin(-d->rotspd);
		d->diry = tmp * sin(-d->rotspd) + d->diry * cos(-d->rotspd);
		tmp = d->planex;
		d->planex = d->planex * cos(-d->rotspd) - d->planey * sin(-d->rotspd);
		d->planey = tmp * sin(-d->rotspd) + d->planey * cos(-M_PI / 30);
	}
	if (d->spdx < 0)
	{
		tmp = d->dirx;
		d->dirx = d->dirx * cos(d->rotspd) - d->diry * sin(d->rotspd);
		d->diry = tmp * sin(d->rotspd) + d->diry * cos(d->rotspd);
		tmp = d->planex;
		d->planex = d->planex * cos(d->rotspd) - d->planey * sin(d->rotspd);
		d->planey = tmp * sin(d->rotspd) + d->planey * cos(d->rotspd);
	}
}

void	update(t_data *d)
{
	double	dirx;
	double	diry;

	update_spd(d);
	dirx = d->dirx * MOVESPEED * d->spdy;
	diry = d->diry * MOVESPEED * d->spdy;
	move(d, dirx, diry);
}
