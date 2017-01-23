/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:24:58 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 11:52:19 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			destroy(t_data *data)
{
	if (data)
		exit(0);
	return (0);
}

int			key_up(int keycode, t_data *d)
{
	if (keycode == W)
		d->keycodes[W] = 0;
	if (keycode == S)
		d->keycodes[S] = 0;
	if (keycode == D)
		d->keycodes[D] = 0;
	if (keycode == A)
		d->keycodes[A] = 0;
	if (keycode == ESC)
		exit(0);
	if (keycode == SHIFT)
		d->sprint = 0;
	return (0);
}

int			key_pressed(int keycode, t_data *d)
{
	if (keycode == W)
		d->keycodes[W] = INITIALSPD;
	if (keycode == S)
		d->keycodes[S] = -INITIALSPD;
	if (keycode == D)
		d->keycodes[D] = INITIALSPD;
	if (keycode == A)
		d->keycodes[A] = -INITIALSPD;
	if (keycode == SHIFT)
		d->sprint = 1.5;
	return (0);
}
