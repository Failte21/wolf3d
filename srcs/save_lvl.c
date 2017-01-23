/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_lvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:51:45 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:32:32 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		save_lvl(t_data d)
{
	int		fd;
	int		x;
	int		y;
	char	current;

	if ((fd = open(d.filename, O_WRONLY)) < 0)
		return ;
	y = -1;
	while (++y < TILECOUNT)
	{
		x = -1;
		while (++x < TILECOUNT)
		{
			current = d.map[y][x] + '0';
			write(fd, &current, 1);
		}
		write(fd, "\n", 1);
	}
	write(fd, "\n", 1);
	close(fd);
}
