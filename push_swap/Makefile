# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 14:50:47 by sab               #+#    #+#              #
#    Updated: 2023/10/06 22:58:52 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
RM = rm -f
OPTIONS = -I

SRC = 	cmd_push.c \
		cmd_reverse_rotate.c \
		cmd_rotate.c \
		cmd_swap.c \
		error.c \
		index_sort.c \
		linked_list.c \
		main.c \
		radix.c \
		tiny_sort.c \

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