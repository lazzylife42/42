/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 19:12:27 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static	int	get_texture_index(char cell)
// {
// 	if (cell == '1')
// 		return (2);
// 	else if (cell == '0')
// 		return (3);
// 	else if (cell == 'P')
// 		return (0);
// 	else if (cell == ' ')
// 		return (0);
// 	return (0);
// }

// void	map_renderer(t_cube *data)
// {
// 	// int		x;
// 	// int		y;
// 	// int		texture_index;

// 	// y = 0;
// 	// while (y < data->map->m_height)
// 	// {
// 	// 	x = 0;
// 	// 	while (x < data->map->m_width)
// 	// 	{
// 	// 		texture_index = get_texture_index(data->map->m_mini_map[y][x]);
// 	// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
// 	// 			data->textures[texture_index], x * 8, (y * 8) + 540);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	// my_mlx_pixel_put(data, (t_vec){0, 540}, 0xFFFFFF);
// 	draw_square(data, (t_vec){0, 540}, 64, 0xFFFFFF);
// }

void	free_map(t_cube *data)
{
	int	i;

	i = 0;
	while (i < data->map->m_height)
	{
		free(data->map->m_mini_map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	data = NULL;
}