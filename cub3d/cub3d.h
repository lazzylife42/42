/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:19:10 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 17:20:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//      INCLUDES        //

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//      DEFINES         //

# define RST "\033[0m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define MAG "\033[1;35m"
# define CYA "\033[1;36m"
# define WHT "\033[1;37m"

# define TRUE 1
# define FALSE 0
# define DEBUG 0
# define MAP_LINE 7
# define X_RES 1280
# define Y_RES 720

# define TEX_NORTH "xpm/tile02.xpm"
# define TEX_WEST "xpm/tile02.xpm"
# define TEX_SOUTH "xpm/tile02.xpm"
# define TEX_EAST "xpm/tile02.xpm"
# define TEX_WALL "xpm/tile02.xpm"
# define TEX_FLOOR "xpm/tile01.xpm"
# define TEX_CEILING "xpm/tile01.xpm"
# define TEX_PLAYER "xpm/kaaris.xpm"

//      STRUCTS         //

typedef struct s_error
{
	int			e_empty;
	int			e_square;
	int			e_walls;
	int			e_overflow;
	int			e_bad_char;
	int			e_bad_map;
	int			e_v_path;
}				t_error;

typedef struct s_player
{
	float		p_pos_x;
	float		p_pos_y;
}				t_player;

typedef struct s_map
{
	int			m_width;
	int			m_height;
	char		**m_mini_map;
	t_player	*player;

}				t_map;

typedef struct s_cube
{
	void		*img;
	char		*addr[6];
	int			*textures[6];
	void		*mlx_ptr;
	void		*win_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	t_map		*map;
}				t_cube;

//      FUNCTIONS       //

int				on_destroy(t_cube *data);

/*		MAP				*/

void			map_init(int fd, t_cube *data);
void			map_dim(int fd, t_cube *data);
void			map_to_tab(int fd, t_cube *data);
void			map_renderer_init(t_cube *data, char **argv);
void			map_sprit_init(t_cube *data);
void			map_renderer(t_cube *data);
void			free_map(t_cube *data);

/*		PLAYER			*/

int				player_move(int keysym, t_cube *data);
void			move_up(t_cube *data);
void			move_left(t_cube *data);
void			move_down(t_cube *data);
void			move_right(t_cube *data);

#endif