# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:10:04 by smonte-e          #+#    #+#              #
#    Updated: 2023/11/24 11:46:14 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OPTIONS = -pthread

SRC = 	src/main.c \
		src/utils.c \
		src/input_check.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OPTIONS) $(OBJS) -o $(NAME)

%.o : $(DIR_SRC)%.c
	gcc $(CFLAGS) $(DIR_SRC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re