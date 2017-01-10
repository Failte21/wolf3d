/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:37:51 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/06 14:06:37 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		new_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

t_color		color_mill(t_color c, t_data *data)
{
	t_color new;

	c.r = data->rp == 1 ? MAP(c.r, 0, data->maxiter, 0, 255) :\
		255 - MAP(c.r, 0, data->maxiter, 0, 255);
	c.g = data->gp == 1 ? MAP(c.r, 0, data->maxiter, 0, 255) :\
		255 - MAP(c.r, 0, data->maxiter, 0, 255);
	c.b = data->bp == 1 ? MAP(c.r, 0, data->maxiter, 0, 255) :\
		255 - MAP(c.r, 0, data->maxiter, 0, 255);
	new = new_color(c.r, c.g, c.b);
	return (new);
}
