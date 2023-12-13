# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 13:40:48 by nreichel          #+#    #+#              #
#    Updated: 2023/12/13 15:16:09 by nreichel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c utils_str.c free.c directory.c minishell_split.c display.c env.c translate.c signal.c alloc.c

OBJS = ${SRCS:.c=.o}

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

USER = nreichel

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
