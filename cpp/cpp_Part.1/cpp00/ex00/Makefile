# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 16:43:14 by smonte-e          #+#    #+#              #
#    Updated: 2024/04/04 17:57:40 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
GCC = g++
SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;32mCompiling $(NAME)...\033[0m"
	$(GCC) $(CFLAGS) $(OPTIONS) $(OBJS) -o $(NAME)

%.o : %.cpp
	@echo "\033[1;36mGenerating object files...\033[0m"
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;33mCleaning object files...\033[0m"
	$(RM) $(OBJS)

fclean: clean
	@echo "\033[1;33mRemoving $(NAME)...\033[0m"
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re

