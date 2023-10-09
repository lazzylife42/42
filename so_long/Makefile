# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 15:31:24 by smonte-e          #+#    #+#              #
#    Updated: 2023/10/09 15:48:11 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
MLX = minilibx
RM = rm -f
OPTIONS = -Imlx -Ilibft

SRC = 	main.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)
	gcc $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -L./$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(OPTIONS)$(DIR_SRC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT)

$(MLX):
	$(MAKE) -C $(MLX)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re