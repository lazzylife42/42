# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 17:48:04 by smonte-e          #+#    #+#              #
#    Updated: 2023/11/04 18:30:02 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
RM = rm -f
OPTIONS = -I

SRC = $(DIR_SRC)main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	gcc $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -o $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(OPTIONS)$(DIR_SRC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re
