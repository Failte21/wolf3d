/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:12:27 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/13 13:14:51 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	init(t_data *d, int x)
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

static void	step_calc(t_data *d)
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

static char	hit(t_data *d, char map[24 * 24])
{
	char	hit;

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
		hit = d->mapy > 0 ? map[d->mapx * d->mapy] : map[d->mapx];
		if (hit > '0')
			return (hit);
	}
}

static void	dist_calc(t_data *d)
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

int		raycast(t_data *d)
{
	t_color	c1;
	t_color	c2;
	int		x;
	char	map[24 * 24]=
	{"111111111111111111111111\
	100000111110000000000001\
	100000111110000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	"100000000000000000000001\
	100000000000000000000001\
	100001100000000000000001\
	100000100000000000000001\
	100000100000000000000001\
	100000100000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	100000000000000000000001\
	111111111111111111111111"};
	c1 = new_color(168, 128, 72);
	c2 = new_color(84, 64, 36);
	x = -1;
	while (x++ < WIDTH)
	{
		init(d, x);
		step_calc(d);
		hit(d, map);
		dist_calc(d);
		if (d->side == 0)
			line(x, c1, *d);
		else
			line(x, c2, *d);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}
