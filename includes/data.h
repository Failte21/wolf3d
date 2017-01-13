/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:48:52 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/13 13:21:46 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_imginf
{
	int		endian;
	int		sl;
	int 	bpp;
	char	*s;
}				t_imginf;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
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
	int			side;
	double		pwalldist;
	int			lineheight;
	int			hit;
	int			drawstart;
	int			drawend;
	char		*map;
	int			mapw;
	int			maph;
}				t_data;


typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

void			update_coord(t_coord coord, int x, int y);
t_data			init_data(void);

#endif
