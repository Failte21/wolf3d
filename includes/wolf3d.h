/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:31:12 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/09 17:22:15 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define A 0
# define S 1
# define D 2
# define G 5
# define B 11
# define W 13
# define L 37
# define R 15
# define P 35
# define J 38
# define M 46
# define SPACE 49
# define ESC 53
# define PLUS 69
# define MINUS 78
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define WIDTH 512
# define HEIGHT 384
# define IMG_WIDTH WIDTH
# define IMG_HEIGHT HEIGHT
# define TILEWIDTH 64
# define CAMERA_H 32
# define WGARGNB 0
# define WGARG 1
# define TITLE "WOLF 3D"
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK (1L<<6)
# define MAP(a, b, c, d, e) (a - b) * (e - d) / (c - b) + d
# define MOVESPEED 0.1

# include "../mlx/mlx.h"
# include <stdio.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "data.h"
# include "coord.h"
# include "color.h"
# include "grid.h"

void			put_px_to_img(t_data data, int x, int y, t_color c);
void			raise_error(int error);
int				key_released(int keycode, t_data *data);
int				key_pressed(int keycode, t_data *data);
int				mouse_motion(int x, int y, t_data *data);
int				mouse_clicked(int button, int x, int y, t_data *data);

#endif
