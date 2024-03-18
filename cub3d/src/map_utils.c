/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:15:11 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/14 14:40:47 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_texture(char *tmp)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0
		|| ft_strncmp(tmp, "SO ", 3) == 0
		|| ft_strncmp(tmp, "EA ", 3) == 0
		|| ft_strncmp(tmp, "WE ", 3) == 0
		|| ft_strncmp(tmp, "F ", 2) == 0
		|| ft_strncmp(tmp, "C ", 2) == 0)
		return (1);
	else
		return (0);
}

int	ft_is_empty(char *line)
{
	while (*line != '\0')
	{
		if (*line != ' ' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

int	is_part_of_map(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		if (buff[i] != '0' && buff[i] != '1'
			&& buff[i] != ' ' && buff[i] != 'N'
			&& buff[i] != 'E' && buff[i] != 'S'
			&& buff[i] != 'W' && buff[i] != 'D')
			return (-1);
		i++;
	}
	return (0);
}
