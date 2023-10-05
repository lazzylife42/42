# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 14:50:47 by sab               #+#    #+#              #
#    Updated: 2023/10/05 16:43:13 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
DIR_SRC = src/
DIR_OBJ = obj/
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
RM = rm -f
OPTIONS = -I

SRC = 	src/main.c \
		src/linked_list.c \
		src/linked_list2.c \
		src/error.c \
		src/find_next_move.c \
		src/price_calculator.c \
		src/cmd_push.c \
		src/cmd_reverse_rotate.c \
		src/cmd_rotate.c \
		src/cmd_swap.c \
		src/tiny_sort.c \
		src/radix.c \

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