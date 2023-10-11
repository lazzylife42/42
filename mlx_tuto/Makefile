# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sab <sab@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 15:02:19 by sab               #+#    #+#              #
#    Updated: 2023/10/11 15:29:29 by sab              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = gcc
FLAG =
DIR_LIB = lib
SRC = main.c
OBJS = $(SRC:.c=.o)
LIBFT = $(DIR_LIB)/libft
MLX = $(DIR_LIB)/minilibx-linux

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)
	$(CC) $(OBJS) -L$(MLX) -lmlx -L/usr/lib -I$(MLX) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I/usr/include -I$(MLX) -O3 -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re
