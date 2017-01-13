/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:10:46 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/13 12:31:44 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				main()
{
	t_data	data;

	data = init_data();
	mlx_hook(data.win, 2, (1L<<0), key_pressed, &data);
	mlx_loop_hook(data.mlx, raycast, &data);
	mlx_key_hook(data.win, key_released, &data);
	mlx_loop(data.mlx);
	return (0);
}
