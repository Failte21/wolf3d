/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:20:22 by lsimon            #+#    #+#             */
/*   Updated: 2017/01/06 13:42:43 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_color;

typedef struct	s_linfo
{
	int		diffx;
	int		diffy;
	int		cumul;
	int		xinc;
	int		yinc;
	t_color	c;
}				t_linfo;

t_color			new_color(unsigned char r, unsigned char g, unsigned char b);
t_color			new_color_hex(char *hexcolor);
void			update_color(t_color *c,
					unsigned char r, unsigned char g, unsigned char b);

#endif
