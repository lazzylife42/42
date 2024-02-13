/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:19:10 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 19:16:47 by smonte-e         ###   ########.fr       */
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

typedef struct s_vec
{
	int			x;
	int			y;
}				t_vec;

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

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_cube
{
	// int			*textures[6];
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_map		*map;
	t_data		*data;
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

/*		DRAW			*/

void			mlx_pixel(t_data *data, t_vec pos, int color);
void			draw_square(t_data data, t_vec pos, int size, int color);

#endif

/*

    Noir:		0x000000
    Blanc:		0xFFFFFF
    Rouge:		0xFF0000
    Vert:		0x008000
    Bleu:		0x0000FF
    Jaune:		0xFFFF00
    Cyan:		0x00FFFF
    Magenta:	0xFF00FF
    Argent:		0xC0C0C0
    Gris: 		0x808080
    Maroon:		0x800000
    Olive:		0x808000
    Vert foncé:	0x008080
    Pourpre:	0x800080
    Teal:		0x008080
    Navy: 		0x000080

*/