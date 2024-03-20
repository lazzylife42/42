# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 17:12:16 by smonte-e          #+#    #+#              #
#    Updated: 2024/03/19 21:24:14 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra -g3 
LIBFT = libft
MLX = minilibx
RM = rm -f
OPTIONS = -Imlx -Ilibft
INCLUDES =  -I/opt/X11/include -Imlx -I.

SRC = src/checker.c src/colors.c src/flood_fill.c src/main.c src/map.c src/map2.c src/player.c src/player2.c src/draw.c \
      src/game_map.c src/keybord.c src/mouse.c src/loadscreen.c src/ray_casting.c src/ray_casting_2.c \
      src/textures.c src/textures_2.c src/door.c src/utils.c src/error.c src/map_checker.c \
	  src/draw_walls.c src/map_dim.c src/map_utils.c src/xpm.c src/rgb.c \
	  src/map_to_tab.c src/mini_map.c src/player_utils.c src/init.c src/textures_utils.c \
	  src/invalid_char.c src/utils_2.c src/check_edges.c src/draw_triangle.c src/free.c

SRC_BONUS = src/checker.c src/colors.c src/flood_fill.c src/main_bonus.c src/map.c src/map2.c src/player.c src/player2.c src/draw.c \
     		src/game_map.c src/keybord.c src/mouse.c src/loadscreen.c src/ray_casting.c src/ray_casting_2.c\
      		src/textures.c src/textures_2.c src/door.c src/utils.c src/error.c src/map_checker.c \
	  		src/draw_walls.c src/map_dim.c src/map_utils.c src/xpm.c src/rgb.c \
			src/map_to_tab.c src/mini_map.c src/player_utils.c src/init.c src/textures_utils.c \
	  		src/invalid_char.c src/utils_2.c src/check_edges.c src/draw_triangle.c src/free.c
	  
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
