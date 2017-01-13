/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:52:45 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/13 12:50:42 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	t_data	data_mlxinit(void)
{
	t_data d;

	if (!(d.mlx = mlx_init()))
		exit(1);
	if (!(d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, TITLE)))
		exit(1);
	if (!(d.img = mlx_new_image(d.mlx, IMG_WIDTH, IMG_HEIGHT)))
		exit(1);
	return (d);
}

t_data			init_data(void)
{
	t_data	d;

	d = data_mlxinit();
	d.w = IMG_WIDTH;
	d.h = IMG_HEIGHT;
	d.posx = 12;
	d.posy = 12;
	d.dirx = -1;
	d.diry = 0;
	d.planex = 0;
	d.planey = 0.66;
	return (d);
}
