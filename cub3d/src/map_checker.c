/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:07:22 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/14 16:31:42 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map_tmp(char **tmp)
{
	if (tmp == NULL)
	{
		free(tmp);
		ft_error(RED "Error\nMalloc Failed\n" RST);
	}
}

char	**copy_map_to_tmp(char **map, t_cube *cube)
{
	char	**tmp;
	int		i;
	int		height;
	int		width;

	height = cube->map->m_height;
	width = cube->map->m_width;
	tmp = (char **)malloc(sizeof(char *) * height + 1);
	i = 0;
	while (i < height)
	{
		tmp[i] = (char *)malloc(width + 1);
		if (tmp[i] == NULL)
		{
			free(tmp[i]);
			ft_error(RED "Error\nMalloc Failed\n" RST);
		}
		ft_strlcpy(tmp[i], map[i], width + 1);
		i++;
	}
	return (tmp);
}

void	free_the_tmp(char **tmp, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;
}

int	is_within_walls(char **map, t_cube *cube)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = copy_map_to_tmp(map, cube);
	while (i < cube->map->m_height)
	{
		j = 0;
		while (j < cube->map->m_width)
		{
			if (check_before_flooding(map, cube, i, j) == -1)
				ft_error(RED "Error\nMap not closed\n" RST);
			if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				flood_fill(tmp, cube, cube->map->player->p_pos_x,
					cube->map->player->p_pos_y);
			j++;
		}
		i++;
	}
	free_the_tmp(tmp, cube->map->m_height);
	return (0);
}
