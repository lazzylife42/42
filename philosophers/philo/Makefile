# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:10:04 by smonte-e          #+#    #+#              #
#    Updated: 2023/11/25 11:40:31 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OPTIONS = -pthread

SRC = 	src/main.c \
		src/utils.c \
		src/input_check.c \
		src/init.c \
		src/thread.c

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