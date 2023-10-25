/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:25:20 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/25 12:12:19 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	void	*img;
	char	*addr[5];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*textures[5];
	char	**map;
	int		map_width;
    int		map_height;
	int		win;
	int		finish;
	int		moves;
} t_data;

/*	MAP	MAKER		*/

void	map_renderer_init(t_data *data, char **argv);
void	map_renderer(t_data *data);
void    map_sprit_init(t_data *data);
void	map_init(int fd, t_data *data);
void	map_dim(int fd, t_data *data);
void	map_to_tab(int fd, t_data *data);
void 	char_to_sprite(t_data *data, char *str);

/*	PLAYER MOVE		*/

int		player_move(int keysym, t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);

/*	GAME STATE	*/

void	game_state(t_data *data);
void	check_c(t_data *data);
void	check_e(t_data *data);

/*	EXIT AND ERROR	*/

int 	on_destroy(t_data *data);
void 	free_map(t_data *data);

#endif