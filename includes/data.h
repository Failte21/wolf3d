/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:48:52 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/23 12:41:53 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_color;

typedef struct	s_imginf
{
	int		endian;
	int		sl;
	int		bpp;
	char	*s;
}				t_imginf;

typedef struct	s_editor
{
	int		focusx;
	int		focusy;
	int		prev_focusx;
	int		prev_focusy;
	t_color	prev_color;
	char	wall;
	char	created;
	int		to_build;
	int		mousedown;
	int		spawnx;
	int		spawny;
	int		spawn_zone;
	int		prev_buildstate;
}				t_editor;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*filename;
	int			w;
	int			h;
	int			tilewidth;
	double		camx;
	double		posx;
	double		posy;
	double		rayposx;
	double		rayposy;
	double		dirx;
	double		diry;
	double		raydirx;
	double		raydiry;
	double		planex;
	double		planey;
	int			stepx;
	int			stepy;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	char		side;
	double		pwalldist;
	int			lineheight;
	int			hit;
	int			drawstart;
	int			drawend;
	int			mapw;
	int			maph;
	char		**map;
	double		spdx;
	double		spdy;
	double		keycodes[300];
	double		sprint;
	char		type;
	char		router;
	t_editor	editor;
	t_color		colors[8];
	double		rotspd;
}				t_data;

t_data			init_data(void);
t_color			new_color(unsigned char r, unsigned char g, unsigned char b);
t_color			new_color_hex(char *hexcolor);
t_color			get_color(char n);
t_color			update_color(t_color c, char n);
t_color			get_prev_color(t_data d);

#endif
