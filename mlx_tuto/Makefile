# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 15:02:19 by sab               #+#    #+#              #
#    Updated: 2023/10/12 17:30:27 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = gcc
FLAG =
DIR_LIB = lib
SRC = main.c
OBJS = $(SRC:.c=.o)
LIBFT = $(DIR_LIB)/libft

OS := $(shell uname)

ifeq ($(OS), Darwin) # macOS
	MLX = $(DIR_LIB)/minilibx
	GRAPHICS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
else # Linux
	MLX = $(DIR_LIB)/minilibx-linux
	GRAPHICS = -L$(MLX) -lmlx -L/usr/lib -I$(MLX) -lXext -lX11 -lm -lz
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)
	$(CC) $(OBJS) $(GRAPHICS) -o $(NAME)

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
