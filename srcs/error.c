/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 09:48:38 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/04 10:01:11 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	raise_error(int error)
{
	if (error == WGARGNB)
		write(2, "Usage: ./fractol fractal name\n", 30);
	if (error == WGARG)
		write(2, "Unknown fractal\n", 16);
	exit(1);
}
