/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:25:20 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/24 18:50:09 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

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
} t_data;

/*	MAP	MAKER	*/

void	map_renderer_init(t_data *data, char **argv);
void	map_renderer(t_data *data);
void    map_sprit_init(t_data *data);
void	map_init(int fd, t_data *data);
void	map_dim(int fd, t_data *data);
void	map_to_tab(int fd, t_data *data);
void 	char_to_sprite(t_data *data, char *str);

#endif