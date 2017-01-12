/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_px_to_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:35:10 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/12 11:43:10 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_px_to_img(t_data data, int x, int y, t_color c)
{
	t_imginf	img;
	int			ppos;

	if (x >= data.w || y >= data.h || y < 0)
		return ;
	if (x < 0)
		return ;
	img.s = mlx_get_data_addr(data.img, &img.bpp, &img.sl, &img.endian);
	img.bpp /= 8;
	ppos = (y * img.sl + x * img.bpp);
	if (img.endian == 0)
	{
		img.s[ppos + 2] = c.r;
		img.s[ppos + 1] = c.g;
		img.s[ppos] = c.b;
	}
	else
	{
		img.s[ppos + 1] = c.r;
		img.s[ppos + 2] = c.g;
		img.s[ppos + 3] = c.b;
	}
}
