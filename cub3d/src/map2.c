/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/14 14:16:02 by smonte-e         ###   ########.fr       */
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

int frame_render(t_cube *data)
{
	data->img->img = mlx_new_image(data->mlx_ptr, X_RES, Y_RES);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel,
		&data->img->line_length, &data->img->endian);
	map_renderer(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img, 0, 0);
	return (0);
}

static	void	player_render(t_cube *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->map->m_height)
	{
		x = 0;
		while (x < data->map->m_width)
		{
			if (data->map->m_mini_map[y][x] == 'P')
				draw_triangle(data->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE}, MINI_SCALE, 0);
			x++;
		}
		y++;
	}
	
}

void	map_renderer(t_cube *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->map->m_height)
	{
		x = 0;
		while (x < data->map->m_width)
		{
			// texture_index = get_texture_index(data->map->m_mini_map[y][x]);
			// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			// 	data->textures[texture_index], x * 8, (y * 8) + 540);
			if (data->map->m_mini_map[y][x] == '1')
				draw_square(data->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE}, MINI_SCALE - 2, 0x909090);
			else if (data->map->m_mini_map[y][x] == '0')
				draw_square(data->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE}, MINI_SCALE - 2, 0xFFFFFF);
			// valeur magique à recalculer !!!
			x++;
		}
		y++;
	}
	player_render(data);
}


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