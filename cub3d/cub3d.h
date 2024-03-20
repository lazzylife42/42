/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:19:10 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/19 22:04:19 by smonte-e         ###   ########.fr       */
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

# define DEBUG 1
# define MAP_LINE 8
# define X_RES 1280
# define Y_RES 720
# define HUD 212
# define TEXTURES_NUM 5
# define MINI_SCALE 16 // valeur magique à recalculer !!!
# define FINE_RATIO 3  // ajuste la vitesse de déplacement
# define ROT_RATIO 5   // vitesse de rotation en Y
# define X_RATIO 5    // vitesse de rotation en X
# define M_SENSITIVITY 0.3

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
# define K_M 46
# define K_O 31

# define LOADSCREEN "xpm/loadscreen.xpm"

/*      STRUCTS         */

typedef struct s_vec
{
	int			x;
	int			y;
}				t_vec;

typedef struct s_vecf
{
	float		x;
	float		y;
}				t_vecf;

typedef struct s_tri
{
	t_vecf		top;
	t_vecf		bottom_left;
	t_vecf		bottom_right;
}				t_tri;

typedef struct s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	int			max_iter;
}				t_draw;

typedef struct s_player
{
	int			p_pos_x;
	int			p_pos_y;
	int			p_pos_a;
	int			offset;
}				t_player;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_textures
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	t_rgb		*f_color;
	t_rgb		*c_color;
}				t_textures;

typedef struct s_map
{
	int			m_width;
	int			m_height;
	bool		mini_map;
	int			m_wall[X_RES][Y_RES];
	char		**m_mini_map;
	double		fps;
	t_player	*player;
	t_textures	*textures;
	t_rgb		*rgb;
	int			map_start;

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
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_text
{
	int			t_width;
	int			t_height;
	t_img		*t_img;
}				t_text;

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
	bool		k_m;
	bool		k_o;
}				t_key;

typedef struct s_raycast
{
	int			color;
	int			side;
	int			hit;
	int			col;
	double		ra;
	double		p_walld;
	double		ratio;
	t_vecf		map;
	t_vecf		dir;
	t_vecf		step;
	t_vecf		sided;
	t_vecf		delta;
	double		camera_height;
	double		wall_height;
	double		wall_center;
	double		wall_top;
	double		wall_bottom;
}				t_raycast;

typedef struct s_cube
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_map		*map;
	t_key		*key;
	t_img		*img;
	t_load		*load;
	t_text		*text;
	t_raycast	*ray;
	bool		loadscreen;
}				t_cube;

//      FUNCTIONS       //

int				on_destroy(t_cube *cube);
int				keypress(int keysym, t_cube *cube);
int				keyrelease(int keysym, t_cube *cube);
int				init_textures(t_cube *cube, t_textures *textures);
void			handle_mouse(t_cube *cube);
void			update_player(t_cube *cube);
void			loadscreen(t_cube *cube);
void			load_transition(t_cube *cube);
void			load_melt_textures(t_cube *cube);
void			handle_door(t_cube *cube);

/*		INIT			*/

void			key_init(t_cube *cube);
void			map_init(t_cube *cube);
void			map_renderer_init(t_cube *cube, char **argv);
void			init_player(t_cube *cube);
void			init_wall(t_cube *cube);

/*		MAP				*/

void			map_dim(int fd, t_cube *cube);
void			map_to_tab(char *arg, t_cube *cube);
void			map_renderer(t_cube *cube);
void			free_map(t_cube *cube);

/*		PLAYER			*/

void			move_front(t_cube *cube);
void			move_back(t_cube *cube);
void			rotate_left(t_cube *cube);
void			rotate_right(t_cube *cube);
void			rotate_up(t_cube *cube);
void			rotate_down(t_cube *cube);
void			move_left(t_cube *cube);
void			move_right(t_cube *cube);

/*		DRAW			*/

void			mlx_pixel(t_img *img, t_vec pos, int color);
void			draw_line(t_img *img, t_vec start, t_vec end, int color);
void			draw_square(t_img *img, t_vec pos, int size, int color);
void			draw_rec(t_img *img, t_vec start, t_vec end, int color);
void			draw_triangle(t_cube *cube);
void			draw_wall(t_cube *cube);
void			draw_textures(t_cube *cube, t_vec start, t_vec end,
					int texture_id);
int				get_texture_color(t_cube *cube, int text_id, t_vec pos);
int				rgb_to_hexa(t_rgb *rgb);

/*		RAYCAST		*/

t_raycast		initialize_raycast(t_cube *cube, int col);
void			perform_dda(t_cube *cube, t_raycast *ray);
void			set_wall_parameters(t_raycast *ray, t_cube *cube,
					double camera_height);
void			render_wall(t_cube *cube, t_raycast *ray);
void			draw_wall(t_cube *cube);

/*			PARSING		*/

int				check_extension(char *arg, char *extension);
int				check_args(int argc);
int				check_existing_file(char *arg);
int				check_map_file(char *arg);
int				check_textures(char *av, t_cube *cube, t_textures *textures);
void			ft_error(char *msg);
void			textures_null(t_textures *textures);
void			find_cardinal(int fd, t_textures *textures);
void			ft_error_long(char *msg1, char *msg2);
char			*extract_path(char *str);
void			init_texture_path(t_textures *textures);
void			check_texture_exists(char *path);
void			check_colors(char **colors, t_rgb *texture);
int				find_commas(char *texture);
int				count_words(char **colors);
void			digit_check(char **colors);
int				get_map_height(t_cube *cube, char *arg, int height,
					int map_start);
void			get_map_width(t_cube *cube, char *arg);
int				ft_isspace(int c);
void			map_delete(t_cube *cube);
int				is_within_walls(char **map, t_cube *cube);
void			get_map_start(t_map *map, char *arg);
int				set_map(char *arg, char **argv, t_cube *cube);
int				ft_is_empty(char *tmp);
int				is_part_of_map(char *buff);
void			flood_fill(char **map, t_cube *cube, int x, int y);
int				ft_strlen_wo_spaces(char *str);
int				is_xpm_file(const char *file_path);
int				validate_rgb_format(char **colors);
t_rgb			*allocate_rgb_mem(void);
char			**split_to_rgb(char *texture);
int				skip_empty_or_single_char_lines(char *buff);
int				open_file(char *file);
void			print_mini_map_header(void);
void			read_and_store_map(int fd, t_cube *cube);
void			initialize_mini_map(t_cube *cube);
void			allocate_and_initialize_row(t_cube *cube,
					int row_index, int width);
void			allocate_mini_map(t_cube *cube);
int				check_players(t_cube *cube);
void			error_players(t_cube *cube);
void			set_player_position(t_cube *cube, int x, int y, char direction);
t_player		*allocate_mem_player(t_cube *cube);
int				init_all(t_cube *cube, char **argv, int argc);
int				init_mlx(t_cube *cube);
int				init_map(t_cube *cube);
int				init_ray_and_img(t_cube *cube);
int				init_window(t_cube *cube);
int				init_load_and_textures(t_cube *cube);
int				count_valid_map_lines(char *file_path);
int				count_total_lines(const char *file_path);
int				skip_lines_before_map(int fd, int num_lines_to_skip);
int				calculate_longest_line_width(int fd, int num_lines);
char			*get_texture_path(int index, t_textures *texture);
int				count_textures(t_textures *textures);
int				load_textures(t_cube *cube, t_textures *textures,
					int texture_count);
int				load_default_textures(t_cube *cube, int index);
int				texture_to_mlx(t_cube *cube, int i, char *file_path);
int				is_valid_char(char letter);
int				check_valid_chars_in_line(char *line);
void			handle_invalid_char(char *line);
void			map_pos(char *tmp);
void			check_duplicates(int i, int *found);
char			*remove_backslash(char *tmp);
void			assign_array(int i, int *found);
int				ft_is_texture(char *tmp);
void			replace_spaces(char *line);
char			*trim_spaces(char *texture);
int				has_textures(char *tmp);
int				has_colors(char *tmp);
int				check_ea_we(char *str);
int				check_line(char *line);
int				check_before_flooding(char **map, t_cube *cube, int i, int j);
int				check_edgy_player(char **map, t_cube *cube, int i, int j);
char			*has_invalid(int fd, char *buff);
void			free_textures(t_textures *textures);
void			free_colors(char **colors);
void			error_wrapper(t_textures *textures, char *error);
char			*get_map_line_start(t_cube *cube, char *buff, int fd);
char			*get_map_line_start_2(t_cube *cube, char *buff, int fd);

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
