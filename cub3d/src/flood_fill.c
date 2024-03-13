/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:13:22 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 10:47:12 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
