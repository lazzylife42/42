/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:23:56 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 18:05:38 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

char	*remove_backslash(char *tmp)
{
	char	*new_tmp;

	if (tmp == NULL)
		return (NULL);
	new_tmp = ft_strchr(tmp, '\n');
	if (new_tmp != NULL)
	{
		*new_tmp = '\0';
		return (tmp);
	}
	return (NULL);
}

void	map_pos(char *tmp)
{
	if (is_part_of_map(tmp) != -1 && ft_is_empty(tmp) != 1)
		ft_error(RED "Error\nMap should be last position\n" RST);
}

int	has_textures(char *tmp)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0
		|| ft_strncmp(tmp, "SO ", 3) == 0
		|| ft_strncmp(tmp, "EA ", 3) == 0
		|| ft_strncmp(tmp, "WE ", 3) == 0)
		return (1);
	else
		return (0);
}

int	has_colors(char *tmp)
{
	if (ft_strncmp(tmp, "F ", 2) == 0 || ft_strncmp(tmp, "C ", 2) == 0)
		return (1);
	else
		return (0);
}
