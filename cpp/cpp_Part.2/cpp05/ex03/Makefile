# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 17:32:48 by smonte-e          #+#    #+#              #
#    Updated: 2024/05/01 18:38:08 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = At\ least\ this\ beats\ coffee-making
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
GCC = g++
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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

fclean: clean
	@echo "\033[1;33mRemoving $(NAME)...\033[0m"
	$(RM) $(NAME)
	@clear

re: fclean all

.PHONY: clean fclean all re