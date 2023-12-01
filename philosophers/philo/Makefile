# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:10:04 by smonte-e          #+#    #+#              #
#    Updated: 2023/12/01 16:21:04 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OPTIONS = -pthread

SRC = 	src/main.c \
		src/utils.c \
		src/parsing.c \
		src/data_init.c \
		src/dinner.c \
		src/getters_setters.c \
		src/sync_utils.c \
		src/safe_functions.c \
		src/monitor.c \
		src/write.c

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