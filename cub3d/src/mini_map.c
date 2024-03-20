/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:17:00 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/14 15:55:04 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	allocate_mini_map(t_cube *cube)
{
	int	height;

	height = cube->map->m_height;
	cube->map->m_mini_map = (char **)malloc((height) * sizeof(char *));
	if (cube->map->m_mini_map == NULL)
		ft_error(RED "Error\nMalloc failed\n" RST);
}

void	allocate_and_initialize_row(t_cube *cube, int row_index, int width)
{
	cube->map->m_mini_map[row_index] = (char *)malloc((width + 1)
			* sizeof(char));
	if (cube->map->m_mini_map[row_index] == NULL)
		ft_error(RED "Error\nMalloc failed\n" RST);
	ft_bzero(cube->map->m_mini_map[row_index], width);
}

void	initialize_mini_map(t_cube *cube)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	width = cube->map->m_width;
	height = cube->map->m_height;
	while (i < height)
	{
		allocate_and_initialize_row(cube, i, width);
		i++;
	}
}

void	map_init(t_cube *cube)
{
	allocate_mini_map(cube);
	initialize_mini_map(cube);
}
