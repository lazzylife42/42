# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 13:40:48 by nreichel          #+#    #+#              #
#    Updated: 2023/12/11 20:54:58 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c utils_str.c free.c directory.c minishell_split.c execute.c exec_pipe.c

OBJS = ${SRCS:.c=.o}

RM		= rm -f

CFLAGS = 

LIBFT_LIB = libft/libft.a


all: compile_other $(NAME)

compile_other:
	make -C libft/ all

$(NAME): $(OBJS)
		gcc -o ${NAME} ${CFLAGS} $(SRCS) $(LIBFT_LIB) -lreadline -fsanitize=address

clean:
		${RM} ${OBJS}
		make -C libft/ clean

fclean:	clean
		${RM} ${NAME}
		make -C libft/ fclean

re:		fclean all
