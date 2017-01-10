/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:24:58 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/06 16:03:21 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == W)
	{
		data->py -= data->movespeed;
		data->ny -= data->movespeed;
	}
	if (keycode == S)
	{
		data->py += data->movespeed;
		data->ny += data->movespeed;
	}
	if (keycode == A)
	{
		data->px -= data->movespeed;
		data->nx -= data->movespeed;
	}
	if (keycode == D)
	{
		data->px += data->movespeed;
		data->nx += data->movespeed;
	}
	return (0);
}

static void	kr2(int keycode, t_data *data)
{
	if (keycode == SPACE)
		data->maxiter = 1;
	if (keycode == ESC)
		exit(0);
	if (keycode == PLUS)
		data->maxiter += 10;
	if (keycode == MINUS)
		data->maxiter = data->maxiter > 10 ? data->maxiter - 10 : data->maxiter;
}

static void	kr1(int keycode, t_data *data)
{
	if (keycode == A)
		data->anim = data->anim == 2 ? 1 : 2;
	if (keycode == S)
		data->f_name = "burning_ship";
	if (keycode == G)
		data->gp = data->gp == 1 ? 0 : 1;
	if (keycode == B)
		data->bp = data->bp == 1 ? 0 : 1;
	if (keycode == M)
		data->f_name = "mandelbrot";
	if (keycode == J)
		data->f_name = "julia";
	if (keycode == R)
		data->rp = data->rp == 1 ? 0 : 1;
	if (keycode == P)
		printf("zx : %f, zy : %f, rp : %d, gp ; %d, bp : %d, %d",
			data->zx, data->zy, data->rp, data->gp, data->bp, data->maxiter);
}

int			key_released(int keycode, t_data *data)
{
	if (keycode < 49)
		kr1(keycode, data);
	else
		kr2(keycode, data);
	return (0);
}
