/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:24:58 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/12 14:37:55 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	key_pressed(int keycode, t_data *d)
{
	if (keycode == W)
	{
		d->posx += d->dirx * MOVESPEED;
		d->posy += d->diry * MOVESPEED;
	}
	if (keycode == S)
	{
		d->posx -= d->dirx * MOVESPEED;
		d->posy -= d->diry * MOVESPEED;
	}
	if (keycode == D)
	{
		double tmp;

		tmp = d->dirx;
		d->dirx = d->dirx * cos(-ROTSPEED) - d->diry * sin(-ROTSPEED);
		d->diry = tmp * sin(-ROTSPEED) + d->diry * cos(-ROTSPEED);
		tmp = d->planex;
		d->planex = d->planex * cos(-ROTSPEED) - d->planey * sin(-ROTSPEED);
		d->planey = tmp * sin(-ROTSPEED) + d->planey * cos(-ROTSPEED);
	}
	if (keycode == D)
{
		double tmp;

		tmp = d->dirx;
		d->dirx = d->dirx * cos(ROTSPEED) - d->diry * sin(ROTSPEED);
		d->diry = tmp * sin(ROTSPEED) + d->diry * cos(ROTSPEED);
		tmp = d->planex;
		d->planex = d->planex * cos(ROTSPEED) - d->planey * sin(ROTSPEED);
		d->planey = tmp * sin(ROTSPEED) + d->planey * cos(ROTSPEED);
}
	return (0);
}

int			key_released(int keycode, t_data *data)
{
	if (!data)
		return (0);
	if (keycode == ESC)
		exit(0);
	return (0);
}
