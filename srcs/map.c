/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:08:28 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:51:21 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	fill_map(t_data *d, char *str)
{
	int			y;
	int			x;
	int			i;

	y = 0;
	i = 0;
	while (y < TILECOUNT)
	{
		x = 0;
		while (x < TILECOUNT)
		{
			d->map[y][x] = str[i] - '0';
			if (d->map[y][x] == 3)
			{
				d->posx = x + 0.5;
				d->posy = y + 0.5;
			}
			if (str[i + 1] == '\n')
				i++;
			i++;
			x++;
		}
		y++;
	}
}

int			map(t_data *d, char *filename)
{
	int			fd;
	int			r;
	char		buff[601];

	r = 0;
	fd = open(filename, O_RDONLY);
	while ((r = read(fd, buff, 601)))
		buff[r] = '\0';
	fill_map(d, buff);
	close(fd);
	return (0);
}
