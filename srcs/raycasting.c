/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:32:54 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/12 14:49:08 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init(t_data *d, int x)
{
	d->camx = 2 * x / (double)WIDTH - 1;
	d->rayposx = d->posx;
	d->rayposy = d->posy;
	d->raydirx = d->dirx + d->planex * d->camx;
	d->raydiry = d->diry + d->planey * d->camx;
	d->mapx = (int)d->rayposx;
	d->mapy = (int)d->rayposy;
	d->deltadistx = sqrt(1 + (d->raydiry * d->raydiry) /
			(d->raydirx * d->raydirx));
	d->deltadisty = sqrt(1 + (d->raydirx * d->raydirx) /
			(d->raydiry * d->raydiry));
	d->hit = 0;
}

void	step_calc(t_data *d)
{
	if (d->raydirx < 0)
	{
		d->stepx = -1;
		d->sidedistx = (d->rayposx - d->mapx) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (d->mapx + 1.0 - d->rayposx) * d->deltadistx;
	}
	if (d->raydiry < 0)
	{
		d->stepy = -1;
		d->sidedisty = (d->rayposy - d->mapy) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (d->mapy + 1.0 - d->rayposy) * d->deltadisty;
	}
}

int		hit_square(t_data *d, int worldmap[24][24])
{
	while (1)
	{
		if (d->sidedistx < d->sidedisty)
		{
			d->sidedistx += d->deltadistx;
			d->mapx += d->stepx;
			d->side = 0;
		}
		else
		{
			d->sidedisty += d->deltadisty;
			d->mapy += d->stepy;
			d->side = 1;
		}
		if (worldmap[d->mapx][d->mapy] > 0)
			return (worldmap[d->mapx][d->mapy]);
	}
	return (0);
}

void	dist_calc(t_data *d)
{
	if (d->side == 0)
		d->pwalldist = (d->mapx - d->rayposx + (1 - d->stepx) /
				2) / d->raydirx;
	else
		d->pwalldist = (d->mapy - d->rayposy + (1 - d->stepy) /
				2) / d->raydiry;
	d->lineheight = (int)(HEIGHT / d->pwalldist);
	d->drawstart = -d->lineheight / 2 + HEIGHT / 2;
	if (d->drawstart < 0)
		d->drawstart = 0;
	d->drawend = d->lineheight / 2 + HEIGHT / 2;
	if (d->drawend >= HEIGHT)
		d->drawend = HEIGHT - 1;
}

void	line(int x, t_color c, t_data *d)
{
	int		y;
	t_color	grd;
	t_color	sky;

	grd = new_color(98, 193, 38);
	sky = new_color(38, 178, 193);
	y = 0;
	while (y < d->drawstart)
	{
		put_px_to_img(*d, x, y, grd);
		y++;
	}
	while (y < d->drawend)
	{
		put_px_to_img(*d, x, y, c);
		y++;
	}
	while (y < d->h)
	{
		put_px_to_img(*d, x, y, sky);
		y++;
	}
}

t_color	get_color(int n, t_data *d)
{
	t_color c;

	if (n == 1)
		c = new_color(16, 67, 150);
	if (n == 2)
		c = new_color(17, 97, 211);
	if (n == 3)
		c = new_color(99, 183, 82);
	if (n == 4)
		c = new_color(66, 150, 150);
	if (d->side == 1)
		c = new_color(0, 0, 0);
	return (c);

}

int		raycast(t_data *d)
{
	t_color	color;
	int		x;
	int		worldmap[24][24]=
	{
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1},
	};

	x = -1;
	while (x++ < WIDTH)
	{
		init(d, x);
		step_calc(d);
		color = get_color(hit_square(d, worldmap), d);
		dist_calc(d);
		line(x, color, d);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}
