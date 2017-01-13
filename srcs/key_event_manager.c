/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:24:58 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/13 13:02:30 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	key_pressed(int keycode, t_data *d)
{
	double	tmp;

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
		tmp = d->dirx;
		d->dirx = d->dirx * cos(-M_PI / 60) - d->diry * sin(-M_PI / 60);
		d->diry = tmp * sin(-M_PI / 60) + d->diry * cos(-M_PI / 60);
		tmp = d->planex;
		d->planex = d->planex * cos(-M_PI / 60) - d->planey * sin(-M_PI / 60);
		d->planey = tmp * sin(-M_PI / 60) + d->planey * cos(-M_PI /
				30);
	}
	if (keycode == A)
	{
		d->olddirx = d->dirx;
		d->dirx = d->dirx * cos(M_PI / 60) - d->diry * sin(M_PI / 60);
		d->diry = d->olddirx * sin(M_PI / 60) + d->diry * cos(M_PI / 60);
		d->oldplanex = d->planex;
		d->planex = d->planex * cos(M_PI / 60) - d->planey * sin(M_PI / 60);
		d->planey = d->oldplanex * sin(M_PI / 60) + d->planey * cos(M_PI / 60);
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
