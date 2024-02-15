/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/15 15:39:40 by smonte-e         ###   ########.fr       */
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

// int frame_render(t_cube *cube)
// {
// 	// cube->img->img = mlx_new_image(cube->mlx_ptr, X_RES, Y_RES);
// 	// cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bits_per_pixel,
// 	// 	&cube->img->line_length, &cube->img->endian);
// 	map_renderer(cube);
// 	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
// 	return (0);
// }

static	void	player_render(t_cube *cube)
{
	int		x;
	int		y;

	y = 0;
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == 'P')
				draw_triangle(cube->img, (t_vec){cube->map->player->p_pos_x, cube->map->player->p_pos_y},
					MINI_SCALE, cube->map->player->p_pos_a);
			x++;
		}
		y++;
	}
	
}

void	map_renderer(t_cube *cube)
{
	int		x;
	int		y;

	y = 0;
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			// texture_index = get_texture_index(cube->map->m_mini_map[y][x]);
			// mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr,
			// 	cube->textures[texture_index], x * 8, (y * 8) + 540);
			if (cube->map->m_mini_map[y][x] == '1')
				draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE}, MINI_SCALE - 2, 0x909090);
			else if (cube->map->m_mini_map[y][x] == '0')
				draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE}, MINI_SCALE - 2, 0xFFFFFF);
			// valeur magique à recalculer !!!
			x++;
		}
		y++;
	}
	player_render(cube);
}


void	free_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < cube->map->m_height)
	{
		free(cube->map->m_mini_map[i]);
		i++;
	}
	free(cube->map);
	cube->map = NULL;
	cube = NULL;
}