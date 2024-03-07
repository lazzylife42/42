# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 17:12:16 by smonte-e          #+#    #+#              #
#    Updated: 2024/03/07 20:09:17 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LIBFT = libft
MLX = minilibx
RM = rm -f
OPTIONS = -Iminilibx/mlx -Ilibftsrc/
INCLUDES = -I/opt/X11/include -Imlx

SRC = src/main.c src/map.c src/map2.c src/player.c src/player2.c src/draw.c \
      src/game_map.c src/keybord.c src/mouse.c src/loadscreen.c src/ray_casting.c \
      src/textures.c src/door.c
	  
SRC_BONUS = src/main_bonus.c src/map.c src/map2.c src/player.c src/player2.c src/draw.c \
      src/game_map.c src/keybord.c src/mouse.c src/loadscreen.c src/ray_casting.c \
		src/textures.c src/door.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

# Colors
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
BLUE = \033[1;36m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(NC)"
	$(MAKE) -sC $(LIBFT)
	$(MAKE) -sC $(MLX)
	gcc $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(INCLUDES)

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
	gcc $(CFLAGS) $(OPTIONS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -sC $(LIBFT)

$(MLX):
	$(MAKE) -sC $(MLX)

bonus: fclean $(OBJS_BONUS)
	@echo "$(GREEN)Compiling bonus...$(NC)"
	$(MAKE) -sC $(LIBFT)
	$(MAKE) -sC $(MLX)
	gcc $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT) -lft -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@clear
	@echo "$(RED)Cleaning...$(NC)"
	$(MAKE) -sC $(LIBFT) clean
	$(MAKE) -sC $(MLX) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(RED)Fcleaning...$(NC)"
	$(RM) $(NAME)
	$(MAKE) -sC $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re
