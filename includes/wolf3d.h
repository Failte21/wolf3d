/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:51:45 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:51:48 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define A 0
# define S 1
# define D 2
# define G 5
# define C 8
# define B 11
# define W 13
# define E 14
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
# define SHIFT 257
# define WIDTH 960
# define HEIGHT 960
# define IMG_WIDTH WIDTH
# define IMG_HEIGHT HEIGHT
# define CAMERA_H 32
# define WGARGNB 0
# define WGARG 1
# define TITLE "WOLF 3D"
# define MAP(a, b, c, d, e) (a - b) * (e - d) / (c - b) + d
# define MOVESPEED 0.1
# define ROTSPEED M_PI / 30
# define MAXSPEED 1.5
# define INITIALSPD 0.3
# define TILECOUNT 24
# define TILEWIDTH 40

# include "../mlx/mlx.h"
# include <stdio.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "data.h"

void			put_px_to_img(t_data data, int x, int y, t_color c);
void			raise_error(int error);
int				key_pressed(int keycode, t_data *data);
int				key_up(int keycode, t_data *data);
int				e_key_pressed(int keycode, t_data *data);
int				e_key_up(int keycode, t_data *data);
int				on_click(int button, int x, int y, t_data *data);
int				e_mouse_up(int button, int x, int y, t_data *data);
int				e_mousedown(int button, int x, int y, t_data *data);
int				e_mousemove(int x, int y, t_data *data);
int				raycast(t_data *d);
void			draw(t_data *d, int x);
int				map(t_data *d, char *filename);
void			mlxinit(t_data d);
void			update(t_data *d);
int				destroy(t_data *data);
int				editor(t_data *d);
void			draw_grid(t_data *d);
void			fill_tile(t_data d, int x, int y, t_color c);
void			save_lvl(t_data d);
void			clr_lvl(t_data *d);
int				game(t_data *d);

#endif
