/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:07:22 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 09:08:24 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_closed_again(char **map, t_cube *cube, int i, int j)
{
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

int	check_edgy_player(char **map, t_cube *cube, int i, int j)
{
	if ((i == 0 || i == cube->map->m_height - 1
			|| j == 0 || j == cube->map->m_width - 1)
		&& (map[i][j] == 'S' || map[i][j] == 'E'
			|| map[i][j] == 'N' || map[i][j] == 'W'
			|| map[i][j] == 'D'))
		return (-1);
	return (0);
}

int	is_within_walls(char **map, t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < cube->map->m_height)
	{
		j = 0;
		while (j < cube->map->m_width)
		{
			if (check_edgy_player(map, cube, i, j) != 0)
				return (-1);
			if ((i == 0 || i == cube->map->m_height - 1
					|| j == 0 || j == cube->map->m_width - 1)
				&& (map[i][j] == '0'))
				return (-1);
			if (map[i][j] == '0' || map[i][j] == ' ')
				flood_fill(map, cube, 0, 0);
			j++;
		}
		i++;
	}
	if (check_map_closed_again(map, cube, i, j) != 0)
		return (-1);
	return (0);
}
