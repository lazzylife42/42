/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:19:10 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/16 00:46:03 by smonte-e         ###   ########.fr       */
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
# include <stdbool.h>
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
# define MAP_LINE 8
# define X_RES 1280
# define Y_RES 720
# define MINI_SCALE 16 // valeur magique à recalculer !!!
# define FINE_RATIO 5
# define ROT_RATIO 5

# define K_ESC 53
# define K_ENTER 36
# define K_LEFT_ARROW 123
# define K_RIGHT_ARROW 124
# define K_UP_ARROW 126
# define K_DOWN_ARROW 125
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2

# define TEX_NORTH "xpm/tile02.xpm"
# define TEX_WEST "xpm/tile02.xpm"
# define TEX_SOUTH "xpm/tile02.xpm"
# define TEX_EAST "xpm/tile02.xpm"
# define TEX_WALL "xpm/tile02.xpm"
# define TEX_FLOOR "xpm/tile01.xpm"
# define TEX_CEILING "xpm/tile01.xpm"
# define TEX_PLAYER "xpm/kaaris.xpm"

# define LOADSCREEN "xpm/loadscreen.xpm"

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
	int			p_pos_x;
	int			p_pos_y;
	int			p_pos_a;
}				t_player;

typedef struct s_map
{
	int			m_width;
	int			m_height;
	int			m_wall[X_RES][Y_RES];
	char		**m_mini_map;
	t_player	*player;

}				t_map;

typedef struct s_melt
{
	void		*img;
	int			width;
	int			height;
}				t_melt;

typedef struct s_load
{
	int			l_width;
	int			l_height;
	void		*l_img;
	t_melt		*melt[31];
}				t_load;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_key
{
	bool		k_esc;
	bool		k_a;
	bool		k_d;
	bool		k_w;
	bool		k_s;
	bool		k_left;
	bool		k_up;
	bool		k_down;
	bool		k_right;
	bool		k_enter;
}				t_key;

typedef struct s_cube
{
	// int			*textures[6];
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_map		*map;
	t_key		*key;
	t_img		*img;
	t_load		*load;
	bool		loadscreen;
}				t_cube;

//      FUNCTIONS       //

int				on_destroy(t_cube *cube);
int				keypress(int keysym, t_cube *cube);
int				keyrelease(int keysym, t_cube *cube);
void			update_player(t_cube *cube);
void			loadscreen(t_cube *cube);
void			load_transition(t_cube *cube);

/*		INIT			*/

void			key_init(t_cube *cube);
void			map_init(int fd, t_cube *cube);
void			map_renderer_init(t_cube *cube, char **argv);
void			init_player(t_cube *cube);
void			init_wall(t_cube *cube);

/*		MAP				*/

void			map_dim(int fd, t_cube *cube);
void			map_to_tab(int fd, t_cube *cube);
void			map_renderer(t_cube *cube);
void			free_map(t_cube *cube);

/*		PLAYER			*/

int				player_move(int keysym, t_cube *cube);
void			move_front(t_cube *cube);
void			move_back(t_cube *cube);
void			rotate_left(t_cube *cube);
void			rotate_right(t_cube *cube);
void			move_up(t_cube *cube);
void			move_left(t_cube *cube);
void			move_down(t_cube *cube);
void			move_right(t_cube *cube);

/*		DRAW			*/

void			mlx_pixel(t_img *img, t_vec pos, int color);
void			draw_line(t_img *img, t_vec start, t_vec end, int color);
void			draw_square(t_img *img, t_vec pos, int size, int color);
void			draw_triangle(t_img *img, t_vec center, int size, float angle);

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
