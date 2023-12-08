# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 14:41:30 by smonte-e          #+#    #+#              #
#    Updated: 2023/12/08 15:15:09 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
DIR_SRC = parser
DIR_INCLUDE = includes
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft
RM = rm -f
OPTIONS = -I$(DIR_INCLUDE)

SRC = parser.c

OBJS = $(addprefix $(DIR_SRC)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	gcc $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -o $(NAME)

$(DIR_SRC)/%.o : $(DIR_SRC)/%.c
	gcc $(CFLAGS) $(OPTIONS) -c $< -o $@

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
