/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:13:22 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/15 18:56:22 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_ea_we(char *str)
{
	int	length;
	int	i;
	int	j;

	i = 0;
	length = ft_strlen(str);
	j = length - 1;
	while (str[i] == 'x')
		i++;
	while (str[j] == 'x')
		j--;
	if (str[i] == '1' && str[j] == '1')
		return (0);
	else
		return (-1);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != 'x' && line[i] != ' ')
			return (0);
		i++;
	}
	return (-1);
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

int	check_before_flooding(char **map, t_cube *cube, int i, int j)
{
	if (check_edgy_player(map, cube, i, j) != 0)
		return (-1);
	if ((i == 0 || i == cube->map->m_height - 1
			|| j == 0 || j == cube->map->m_width - 1)
		&& (map[i][j] == '0'))
		return (-1);
	return (0);
}
