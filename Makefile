# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 17:31:23 by lsimon            #+#    #+#              #
#    Updated: 2017/01/13 12:29:42 by lsimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Ofast -march=native -O2 -g

LDFLAGS = -framework OpenGl -framework Appkit

LINKS = libft/libft.a mlx/libmlx.a

SRC = srcs/main.c srcs/data.c srcs/put_px_to_img.c srcs/raycasting.c\
		srcs/color.c srcs/key_event_manager.c srcs/lines.c

OBJS = $(SRC:.c=.o)

NAME = wolf3d

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(LDFLAGS) $(LINKS) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft
	make clean -C mlx

re: fclean all
