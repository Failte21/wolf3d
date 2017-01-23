/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:00:50 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:48:02 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	fill_tile(t_data d, int x, int y, t_color c)
{
	int	px;
	int	py;
	int	targetx;
	int	targety;

	py = y * TILEWIDTH;
	targety = py + TILEWIDTH;
	while (py++ < targety)
	{
		px = x * TILEWIDTH;
		targetx = px + TILEWIDTH;
		while (px++ < targetx)
			put_px_to_img(d, px, py, c);
	}
}

void	replace(int x, int y, t_data *d)
{
	if (x == 0 || y == 0 || x == TILECOUNT - 1 || y == TILECOUNT - 1)
	{
		fill_tile(*d, x, y, d->colors[6]);
		d->map[y][x] = 1;
	}
	else if (x == 1 && y == 1)
	{
		fill_tile(*d, x, y, d->colors[5]);
		d->editor.spawnx = x;
		d->editor.spawny = y;
		d->map[y][x] = 3;
	}
	else
	{
		fill_tile(*d, x, y, d->colors[7]);
		d->map[y][x] = 0;
	}
}

void	clr_lvl(t_data *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < TILECOUNT)
	{
		x = -1;
		while (++x < TILECOUNT)
		{
			replace(x, y, d);
		}
	}
}

void	draw_grid(t_data *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < TILECOUNT)
	{
		x = -1;
		while (++x < TILECOUNT)
		{
			if (d->map[y][x] == 1)
				fill_tile(*d, x, y, d->colors[6]);
			else if (d->map[y][x] == 3)
			{
				fill_tile(*d, x, y, d->colors[5]);
				d->editor.spawnx = x;
				d->editor.spawny = y;
			}
			else
				fill_tile(*d, x, y, d->colors[7]);
		}
	}
}

int		editor(t_data *d)
{
	if (d->editor.to_build == 1 &&
			d->map[d->editor.focusy][d->editor.focusx] != 3)
	{
		fill_tile(*d, d->editor.focusx, d->editor.focusy, d->colors[6]);
		d->map[d->editor.focusy][d->editor.focusx] = 1;
	}
	else if (d->editor.to_build == 2 &&
			d->map[d->editor.focusy][d->editor.focusx] != 3)
	{
		fill_tile(*d, d->editor.focusx, d->editor.focusy, d->colors[7]);
		d->map[d->editor.focusy][d->editor.focusx] = 0;
	}
	else if (d->editor.to_build == 3)
	{
		fill_tile(*d, d->editor.spawnx, d->editor.spawny, d->colors[7]);
		fill_tile(*d, d->editor.focusx, d->editor.focusy, d->colors[5]);
		d->map[d->editor.spawny][d->editor.spawnx] = 0;
		d->map[d->editor.focusy][d->editor.focusx] = 3;
		d->editor.spawnx = d->editor.focusx;
		d->editor.spawny = d->editor.focusy;
		d->editor.to_build = d->editor.prev_buildstate;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}
