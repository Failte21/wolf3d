/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:37:51 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/19 10:15:41 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_color		new_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

t_color		get_prev_color(t_data d)
{
	int		current_tile;

	if (d.editor.focusx < 0)
		return (new_color(255, 255, 255));
	current_tile = d.map[d.editor.focusy][d.editor.focusx];
	if (current_tile > 0)
		return (new_color(0, 0, 0));
	else
		return (new_color(255, 255, 255));
}

t_color		get_color(char n)
{
	t_color	c;

	if (n == 1)
		c = new_color(101, 103, 198);
	if (n == 2)
		c = new_color(175, 129, 89);
	if (n == 3)
		c = new_color(153, 73, 80);
	if (n == 4)
		c = new_color(107, 104, 105);
	return (c);
}

t_color		update_color(t_color c, char n)
{
	return (new_color(c.r / n, c.g / n, c.b / 2));
}
