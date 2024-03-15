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

int	check_map_closed_again(char **map, t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (i < cube->map->m_height)
	{
		j = 0;
		while (j < cube->map->m_width)
		{
			if (map[i][j] == '2')
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

char 	**copy_map_to_tmp(char **map, t_cube *cube)
{
	char **tmp;
	int i;
	int j;

	tmp = (char **)malloc(sizeof(char *) * cube->map->m_height + 1);
	if (tmp == NULL)
		ft_error(RED "Error\nMalloc Failed\n" RST);
	i = 0;
	while (i < cube->map->m_height)
	{
		j = 0;
		tmp[i] = (char *)malloc(ft_strlen(map[i]) + 1);
		if (tmp[i] == NULL)
			ft_error(RED "Error\nMalloc Failed\n" RST);
		ft_strlcpy(tmp[i], map[i], ft_strlen(map[i]) + 1);
		//if (DEBUG == 1)
		//	ft_printf(BLU "%s\n" RST, tmp[i]);
		i++;
	}
	return (tmp);
}

int	is_within_walls(char **map, t_cube *cube)
{
	int	i;
	int	j;
	char	**tmp;


	i = 0;
	tmp = copy_map_to_tmp(map, cube);
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
			if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				flood_fill(tmp, cube, cube->map->player->p_pos_x, cube->map->player->p_pos_y);
			j++;
		}
		i++;
	}
	//TODO: free tmp when creating tmp en cas d'echec + after flood_fill
	return (0);
}
