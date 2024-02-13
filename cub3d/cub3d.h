/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:19:10 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 12:27:41 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//      INCLUDES        //

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

//      DEFINES         //

# define RST "\033[0m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define MAG "\033[1;35m"
# define CYA "\033[1;36m"
# define WHT "\033[1;37m"

# define TRUE  1
# define FALSE 0
# define DEBUG 0
# define X_RES 1280
# define Y_RES 720

//      STRUCTS         //

typedef struct s_error
{
	int		empty;
	int		square;
	int		walls;
	int		overflow;
	int		bad_char;
	int		bad_map;
	int		v_path;
}	t_error;

typedef struct s_data
{
	void	*img;
	char	*addr[6];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*textures[6];
	char	**map;
	int		map_width;
	int		map_height;
}	t_data;

//      FUNCTIONS       //

#endif