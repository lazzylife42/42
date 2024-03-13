/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:15:11 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 09:16:21 by lmedrano         ###   ########.fr       */
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

int	ft_is_empty(char *tmp)
{
	size_t	i;

	i = 0;
	if (tmp == NULL)
		return (0);
	if (ft_strlen(tmp) == 1)
		return (1);
	while (tmp[i] != '\n')
	{
		if (ft_isspace(tmp[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_wo_spaces(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			count++;
		i++;
	}
	return (count);
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
