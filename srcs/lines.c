/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:49:53 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/12 12:04:06 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		dl1(t_data data, t_coord start, t_linfo linfo)
{
	int	x;
	int	y;
	int	i;

	x = start.x;
	y = start.y;
	i = 0;
	linfo.cumul = linfo.diffx / 2;
	while (i < linfo.diffx)
	{
		x += linfo.xinc;
		linfo.cumul += linfo.diffy;
		if (linfo.cumul >= linfo.diffx)
		{
			linfo.cumul -= linfo.diffx;
			y += linfo.yinc;
		}
		put_px_to_img(data, x, y, linfo.c);
		i++;
	}
}

static void		dl2(t_data data, t_coord start, t_linfo linfo)
{
	int	x;
	int	y;
	int	i;

	x = start.x;
	y = start.y;
	i = 0;
	linfo.cumul = linfo.diffy / 2;
	while (i < linfo.diffy)
	{
		y += linfo.yinc;
		linfo.cumul += linfo.diffx;
		if (linfo.cumul >= linfo.diffy)
		{
			linfo.cumul -= linfo.diffy;
			x += linfo.xinc;
		}
		put_px_to_img(data, x, y, linfo.c);
		i++;
	}
}

void			line(t_data data, t_coord start, t_coord end, t_color color)
{
	t_linfo	linfo;

	linfo.xinc = MOP(end.x - start.x);
	linfo.yinc = MOP(end.y - start.y);
	linfo.diffx = abs(end.x - start.x);
	linfo.diffy = abs(end.y - start.y);
	linfo.c = color;
	put_px_to_img(data, start.x, start.y, linfo.c);
	if (linfo.diffx > linfo.diffy)
		dl1(data, start, linfo);
	else
		dl2(data, start, linfo);
}
