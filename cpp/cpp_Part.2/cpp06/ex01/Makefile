# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 15:22:29 by smonte-e          #+#    #+#              #
#    Updated: 2024/05/17 15:41:22 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialization
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
GCC = g++
SRC = main.cpp Serialization.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;32mCompiling $(NAME)...\033[0m"
	$(GCC) $(CFLAGS) $(OPTIONS) $(OBJS) -o $(NAME)
	@clear

%.o : %.cpp
	@echo "\033[1;36mGenerating object files...\033[0m"
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;33mCleaning object files...\033[0m"
	$(RM) $(OBJS)
	@clear

fclean: clean
	@echo "\033[1;33mRemoving $(NAME)...\033[0m"
	$(RM) $(NAME)
	@clear

re: fclean all

.PHONY: clean fclean all re