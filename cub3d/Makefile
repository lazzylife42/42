# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 15:31:24 by smonte-e          #+#    #+#              #
#    Updated: 2024/02/13 18:05:14 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LIBFT = libft
MLX = minilibx
RM = rm -f
OPTIONS = -Imlx -Ilibft
INCLUDES = -I/opt/X11/include -Imlx

SRC = src/main.c src/map.c src/map2.c src/player.c src/draw.c

SRC_BONUS = src/main.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m

# Silence make
ifeq ($(SILENT),true)
.SILENT:
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(NC)"
	$(MAKE) -sC $(LIBFT)
	@echo "$(GREEN)Making libft...$(NC)"
	$(MAKE) -sC $(MLX)
	@echo "$(GREEN)Making minilibx...$(NC)"
	gcc $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -L./$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	@clear
	@echo "$(BLUE)\
	\n\n\
	\t\t\t░█████╗░██╗░░░██╗██████╗░██████╗░██████╗░\n\
	\t\t\t██╔══██╗██║░░░██║██╔══██╗╚════██╗██╔══██╗\n\
	\t\t\t██║░░╚═╝██║░░░██║██████╦╝░█████╔╝██║░░██║\n\
	\t\t\t██║░░██╗██║░░░██║██╔══██╗░╚═══██╗██║░░██║\n\
	\t\t\t╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝\n\
	\t\t\t░╚════╝░░╚═════╝░╚═════╝░╚═════╝░╚═════╝░\n\
	\n$(NC)"
	@echo "$(YELLOW)Compiling src...$(NC)"
	gcc $(CFLAGS) $(OPTIONS)$(DIR_SRC) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -sC $(LIBFT)

$(MLX):
	$(MAKE) -sC $(@D)

bonus: fclean $(OBJS_BONUS)
	@echo "$(GREEN)Compiling bonus...$(NC)"
	$(MAKE) -sC $(LIBFT)
	$(MAKE) -sC $(MLX)
	gcc $(CFLAGS) $(OBJS_BONUS) -L./$(LIBFT) -lft -L./$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@clear
	@echo "$(RED)Cleaning...$(NC)"
	$(MAKE) -sC $(LIBFT) clean
	$(MAKE) -sC $(MLX) clean
	$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)Fcleaning...$(NC)"
	$(RM) $(NAME)
	$(MAKE) -sC $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re
