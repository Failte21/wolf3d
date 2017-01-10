/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:10:46 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/10 10:37:14 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				main(int argc, char **argv)
{
	t_data	data;
	char	*mqp;

	map = "11111\n10001\n10001\n10001\n11111";

	data = init_data();
	data.f_name = argv[1];
	mlx_key_hook(data.w, key_released, &data);
	mlx_hook(data.w, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion, &data);
	mlx_hook(data.w, 2, (1L<<0), key_pressed, &data);
	mlx_mouse_hook(data.w, mouse_clicked, &data);
	mlx_loop_hook(data.mlx, draw, &data);
	mlx_loop(data.mlx);
	return (0);
}
