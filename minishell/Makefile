# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 13:40:48 by nreichel          #+#    #+#              #
#    Updated: 2023/12/11 14:17:48 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c utils_str.c free.c directory.c execute.c

OBJS = ${SRCS:.c=.o}

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

LIBFT_LIB = libft/libft.a


all: compile_other $(NAME)

compile_other:
	make -C libft/ all

$(NAME): $(OBJS)
		gcc -o ${NAME} ${CFLAGS} $(SRCS) $(LIBFT_LIB) -lreadline

clean:
		${RM} ${OBJS}
		make -C libft/ clean

fclean:	clean
		${RM} ${NAME}
		make -C libft/ fclean

re:		fclean all