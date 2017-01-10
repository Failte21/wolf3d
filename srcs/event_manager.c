/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:03:57 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/06 14:23:43 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom(t_data *d, double x, double y, unsigned char dir)
{
	double	mapx;
	double	mapy;

	if (dir == 4)
	{
		d->xratio /= ZOOMSPEED;
		d->yratio /= ZOOMSPEED;
	}
	else
	{
		d->xratio *= ZOOMSPEED;
		d->yratio *= ZOOMSPEED;
	}
	mapx = MAP(x, 0, WIDTH, d->nx, d->px);
	mapy = MAP(y, 0, WIDTH, d->ny, d->py);
	d->nx = mapx - d->xratio / 2;
	d->px = d->nx + d->xratio;
	d->ny = mapy - d->yratio / 2;
	d->py = d->ny + d->yratio;
}

int			mouse_motion(int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	dx = x;
	dy = y;
	if (data->locked == 1)
		return (0);
	data->zx = MAP(dx, 0, IMG_WIDTH, -RANGE, RANGE);
	data->zy = MAP(dy, 0, IMG_HEIGHT, -RANGE, RANGE);
	return (0);
}

int			mouse_clicked(int button, int x, int y, t_data *data)
{
	double dx;
	double dy;

	dx = x;
	dy = y;
	if (button == 4 || button == 5)
		zoom(data, dx, dy, button);
	if (button == 1 && ft_strcmp(data->f_name, "julia") == 0)
		data->locked = data->locked == 1 ? 0 : 1;
	return (0);
}
