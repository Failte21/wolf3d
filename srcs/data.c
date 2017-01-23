/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:52:45 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:37:18 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char			**init_map(void)
{
	int		i;
	char	**array;

	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * TILECOUNT + 1)))
		exit(1);
	while (i < 24)
	{
		if (!(array[i] = (char *)malloc(sizeof(char) * TILECOUNT + 1)))
			exit(1);
		ft_bzero(array[i], TILECOUNT + 1);
		i++;
	}
	return (array);
}

static void		init_colors(t_data *d)
{
	d->colors[0] = new_color(66, 134, 244);
	d->colors[1] = new_color(18, 168, 90);
	d->colors[2] = new_color(146, 152, 229);
	d->colors[3] = new_color(224, 223, 130);
	d->colors[4] = new_color(255, 255, 255);
	d->colors[5] = new_color(255, 0, 0);
	d->colors[6] = new_color(0, 0, 0);
	d->colors[7] = new_color(255, 255, 255);
}

static t_editor	init_editor(void)
{
	t_editor e;

	e.focusx = -1;
	e.focusy = -1;
	e.prev_focusx = -1;
	e.prev_focusx = -1;
	e.wall = 0;
	e.created = 0;
	e.prev_color = new_color(255, 255, 255);
	e.to_build = 0;
	e.mousedown = 0;
	e.spawn_zone = 0;
	e.prev_buildstate = 0;
	return (e);
}

static void		mlxinitdata(t_data *d)
{
	if (!(d->mlx = mlx_init()))
		exit(1);
	if (!(d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, TITLE)))
		exit(1);
	if (!(d->img = mlx_new_image(d->mlx, IMG_WIDTH, IMG_HEIGHT)))
		exit(1);
}

t_data			init_data(void)
{
	t_data	d;

	mlxinitdata(&d);
	d.w = IMG_WIDTH;
	d.h = IMG_HEIGHT;
	d.dirx = -1;
	d.diry = 0;
	d.planex = 0;
	d.planey = 0.66;
	d.spdx = 0;
	d.spdy = 0;
	ft_bzero(d.keycodes, 300);
	d.sprint = 0;
	d.editor = init_editor();
	d.map = init_map();
	d.type = 2;
	d.router = 0;
	init_colors(&d);
	d.rotspd = ROTSPEED;
	bzero(d.keycodes, 0);
	d.filename = "map.w3d";
	return (d);
}
