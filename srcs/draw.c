/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:45:34 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:07:38 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	line(int x, t_color color, t_data data)
{
	int		i;

	i = -1;
	while (i++ < HEIGHT)
	{
		if (i < data.drawstart)
			put_px_to_img(data, x, i, data.colors[4]);
		else if (i > data.drawend)
			put_px_to_img(data, x, i, data.colors[5]);
		else
			put_px_to_img(data, x, i, color);
	}
}

void		draw(t_data *d, int x)
{
	t_color c;

	if (d->side == 0)
	{
		if (d->mapx < d->posx)
			c = d->colors[0];
		else
			c = d->colors[1];
	}
	else
	{
		if (d->mapy < d->posy)
			c = d->colors[2];
		else
			c = d->colors[3];
	}
	line(x, c, *d);
}
