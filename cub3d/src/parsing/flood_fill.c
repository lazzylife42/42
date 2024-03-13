/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:13:22 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/12 14:02:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_flood_x(int flood_x[4])
{
	flood_x[0] = 1;
	flood_x[1] = -1;
	flood_x[2] = 0;
	flood_x[3] = 0;
}

void	init_flood_y(int flood_y[4])
{
	flood_y[0] = 0;
	flood_y[1] = 0;
	flood_y[2] = 1;
	flood_y[3] = -1;
}

void	flood_fill(char **map, t_cube *cube, int x, int y)
{
	int	width;
	int	height;
	int	i;
	int	flood_x[4];
	int	flood_y[4];

	i = 0;
	width = cube->map->m_width;
	height = cube->map->m_height;
	init_flood_x(flood_x);
	init_flood_y(flood_y);
	if (x < 0 || x >= width || y < 0 || y >= height
		|| map[x][y] == '1' || map[x][y] == '2')
		return ;
	map[x][y] = '2';
	while (i < 4)
	{
		flood_fill(map, cube, x + flood_x[i], y + flood_y[i]);
		i++;
	}
}

int	is_within_walls(char **map, t_cube *cube)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = 0;
	start_y = 0;
	i = 0;
	while (i < cube->map->m_height)
	{
		j = 0;
		while (j < cube->map->m_width)
		{
			if ((i == 0 || i == cube->map->m_height - 1
					|| j == 0 || j == cube->map->m_width - 1)
				&& (map[i][j] == 'S' || map[i][j] == 'E'
					|| map[i][j] == 'N' || map[i][j] == 'W'))
				return (-1);
			if ((i == 0 || i == cube->map->m_height - 1
					|| j == 0 || j == cube->map->m_width - 1)
				&& (map[i][j] == '0'))
				return (-1);
			if (map[i][j] == '0' || map[i][j] == ' ')
				flood_fill(map, cube, start_x, start_y);
			j++;
		}
		i++;
	}
	while (i < cube->map->m_height)
	{
		j = 0;
		while (j < cube->map->m_width)
		{
			if (map[i][j] == '0' || map[i][j] == ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
