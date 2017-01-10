/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:48:52 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/10 13:29:10 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "grid.h"

typedef struct	s_data
{
	void			*mlx;
	void			*w;
	void			*img;
	int				w;
	int				h;
	int				tilewidth;
}				t_data;

typedef struct	s_imginf
{
	int		endian;
	int		sl;
	int 	bpp;
	char	*s;
}				t_imginf;

typedef struct	s_pos
{
	double		camx;
	double		posx;
	double		posy;
	double		rayposx;
	double		rayposY;
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
},				t_pos;

t_data			init_data(void);

#endif
