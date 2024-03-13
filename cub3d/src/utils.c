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

void	assign_array(int i, int *found)
{
	while (i < 6)
	{
		found[i] = 0;
		i++;
	}
}

void	check_duplicates(int i, int *found)
{
	while (i < 6)
	{
		if (found[i] > 1)
			ft_error(RED "Error\nDuplicated texture\n" RST);
		i++;
	}
}

void	map_pos(char *tmp)
{
	if (is_part_of_map(tmp) != -1 && ft_is_empty(tmp) != 1)
		ft_error(RED "Error\nMap should be last position\n" RST);
}
