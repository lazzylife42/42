/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/07 21:21:40 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_render(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == 'P')
				draw_triangle(cube);
			x++;
		}
		y++;
	}
}

void	map_renderer(t_cube *cube)
{
	int	x;
	int	y;

	draw_rec(cube->img, (t_vec){0, 0}, (t_vec){X_RES, Y_RES / 2
		- cube->map->player->offset}, 0x000080);
	draw_wall(cube);
	y = 0;
	while (cube->map->mini_map && y < cube->map->m_height)
	{
		x = 0;
		while (cube->map->mini_map && x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == '1')
				draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
					MINI_SCALE - 2, 0x909090);
			else if (cube->map->m_mini_map[y][x] == '0' || cube->map->m_mini_map[y][x] == 'P')
				draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
					MINI_SCALE - 2, 0xFFFFFF);
			else if (cube->map->m_mini_map[y][x] == 'D')
				draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
					MINI_SCALE - 2, 0xFF0000);
			else if (cube->map->m_mini_map[y][x] == 'd')
				draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
					MINI_SCALE - 2, 0x800080);
			x++;
		}
		y++;
	}
	if (cube->map->mini_map)
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
