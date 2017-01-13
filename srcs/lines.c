/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:27:37 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/13 11:28:43 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	line(int x, t_color color, t_data data)
{
	int		i;
	t_color	sky;
	t_color	ground;

	sky = new_color(175, 206, 255);
	ground = new_color(56, 46, 33);
	i = -1;
	while (i++ < HEIGHT)
	{
		if (i < data.drawstart)
			put_px_to_img(data, x, i, sky);
		else if (i > data.drawend)
			put_px_to_img(data, x, i, ground);
		else
			put_px_to_img(data, x, i, color);
	}
}
