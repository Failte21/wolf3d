# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 17:31:23 by lsimon            #+#    #+#              #
#    Updated: 2017/01/10 11:00:01 by lsimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Ofast -march=native -O2

LDFLAGS = -framework OpenGl -framework Appkit

LINKS = libft/libft.a mlx/libmlx.a

SRC = srcs/main.c srcs/data.c srcs/put_px_to_img.c \

OBJS = $(SRC:.c=.o)

NAME = wolf3d

all: $(NAME)

fractol: $(OBJS)
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
