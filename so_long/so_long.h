/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:25:20 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/20 01:17:53 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**layout;
}t_map;

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
	t_map	*map;
} t_data;

/*	MAP	MAKER	*/
void 	map_to_str(t_data data);
void	sprite_init(t_data data);
void 	char_to_sprite(t_data data, char *str);

#endif