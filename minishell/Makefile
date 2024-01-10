# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 13:40:48 by nreichel          #+#    #+#              #
#    Updated: 2024/01/10 20:09:42 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c utils_str.c free.c  minishell_split.c translate.c signal.c alloc.c execute.c\
	builtin/directory.c builtin/display.c builtin/env.c\
	parser/llist.c parser/parser.c parser/parser_utils.c parser/heredoc.c 

OBJS = ${SRCS:.c=.o}

RM	= rm -f

CFLAGS = -Wall -Wextra -Werror -g

USER := $(shell whoami)

LIBFT_LIB = libft/libft.a

all: compile_other $(NAME)

compile_other:
	make -C libft/ all

$(NAME): $(OBJS)
		gcc -o ${NAME} ${CFLAGS} $(SRCS) $(LIBFT_LIB) -lreadline -L/Users/${USER}/.brew/opt/readline/lib -I/Users/${USER}/.brew/opt/readline/include -fsanitize=address

clean:
		${RM} ${OBJS}
		make -C libft/ clean

fclean:	clean
		${RM} ${NAME}
		make -C libft/ fclean

re:		fclean all
