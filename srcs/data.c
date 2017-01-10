/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:52:45 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/10 12:55:25 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	t_data	data_mlxinit(void)
{
	t_data n;

	if (!(n.mlx = mlx_init()))
		exit(1);
	if (!(n.w = mlx_new_window(n.mlx, WIDTH, HEIGHT, TITLE)))
		exit(1);
	if (!(n.img = mlx_new_image(n.mlx, IMG_WIDTH, IMG_HEIGHT)))
		exit(1);
	return (n);
}

t_data			init_data(void)
{
	t_data	d;

	d = data_mlxinit();
	d.w = IMG_WIDTH;
	d.h = IMG_HEIGHT;
	return (d);
}

t_pos	init_pos()
{
	t_pos	new;

	new.posx = 100;
	new.posy = 100;
	new.dirx = -1;
	new.diry = 0;
	new.rayposx = new.posx;
	new.rayposy = new.posy;
	new.planex = 0;
	new.planey = 0.66;
}
