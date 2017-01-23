/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_key_event_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:39:44 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 11:18:12 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			e_destroy(t_data *data)
{
	if (data)
		exit(0);
	return (0);
}

int			e_mousemove(int x, int y, t_data *d)
{
	if (x < TILEWIDTH || x > WIDTH - TILEWIDTH ||
			y < TILEWIDTH || y > WIDTH - TILEWIDTH)
		return (0);
	d->editor.focusx = x / TILEWIDTH;
	d->editor.focusy = y / TILEWIDTH;
	return (0);
}

int			e_mousedown(int button, int x, int y, t_data *d)
{
	if (x < TILEWIDTH || x > WIDTH - TILEWIDTH ||
			y < TILEWIDTH || y > WIDTH - TILEWIDTH)
		return (0);
	d->editor.focusx = x / TILEWIDTH;
	d->editor.focusy = y / TILEWIDTH;
	d->editor.to_build = button;
	return (0);
}

int			e_mouse_up(int button, int x, int y, t_data *d)
{
	button = 0;
	x = 0;
	y = 0;
	d->editor.to_build = 0;
	return (0);
}

int			e_key_up(int keycode, t_data *d)
{
	t_color red;

	red = new_color(255, 255, 255);
	if (!d)
		return (0);
	if (keycode == ESC)
		exit(1);
	if (keycode == SPACE)
	{
		d->editor.prev_buildstate = d->editor.to_build;
		d->editor.to_build = 3;
	}
	if (keycode == S)
		save_lvl(*d);
	if (keycode == C)
		clr_lvl(d);
	return (0);
}
