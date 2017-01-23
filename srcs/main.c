/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:10:46 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:31:50 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_data	data;

	data = init_data();
	data.type = (argc > 1 && ft_strcmp(argv[1], "-e") == 0) ? 2 : 1;
	map(&data, data.filename);
	draw_grid(&data);
	if (data.type == 1)
	{
		mlx_hook(data.win, 2, (1L << 0), key_pressed, &data);
		mlx_hook(data.win, 3, (1L << 1), key_up, &data);
	}
	else
	{
		mlx_hook(data.win, 3, (1L << 1), e_key_up, &data);
		mlx_hook(data.win, 5, (1L << 3), e_mouse_up, &data);
		mlx_hook(data.win, 4, (1L << 2), e_mousedown, &data);
		mlx_hook(data.win, 6, (1L << 6), e_mousemove, &data);
	}
	mlx_hook(data.win, 17, (1L << 17), destroy, &data);
	mlx_loop_hook(data.mlx, game, &data);
	mlx_loop(data.mlx);
	return (0);
}
