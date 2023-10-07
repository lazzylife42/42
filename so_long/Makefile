# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 15:31:24 by smonte-e          #+#    #+#              #
#    Updated: 2023/10/07 15:43:21 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
MLX = minilibx
RM = rm -f
OPTIONS = -I

SRC = 	main.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	gcc $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -L./$(MLX) -lmlx -o $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(OPTIONS)$(DIR_SRC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(MLX)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re