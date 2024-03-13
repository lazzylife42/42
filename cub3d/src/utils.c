/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:23:56 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/11 18:34:26 by lmedrano         ###   ########.fr       */
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

void	find_cardinal(int fd, t_textures *textures)
{
	char		*tmp;

	tmp = get_next_line(fd);
	if (is_part_of_map(tmp) != -1 && ft_is_empty(tmp) != 1)
		ft_error(RED "Error\nMap should be last position\n" RST);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp, "NO ", 3) == 0)
			textures->no = remove_backslash(tmp + 3);
		if (ft_strncmp(tmp, "SO ", 3) == 0)
			textures->so = remove_backslash(tmp + 3);
		if (ft_strncmp(tmp, "EA ", 3) == 0)
			textures->ea = remove_backslash(tmp + 3);
		if (ft_strncmp(tmp, "WE ", 3) == 0)
			textures->we = remove_backslash(tmp + 3);
		if (ft_strncmp(tmp, "F ", 2) == 0)
			textures->f = remove_backslash(tmp + 2);
		if (ft_strncmp(tmp, "C ", 2) == 0)
			textures->c = remove_backslash(tmp + 2);
		tmp = get_next_line(fd);
	}
	if (DEBUG == 1)
	{
		printf("No is <%s>\n", textures->no);
		printf("So is <%s>\n", textures->so);
		printf("Ea is <%s>\n", textures->ea);
		printf("We is <%s>\n", textures->we);
		printf("F is <%s>\n", textures->f);
		printf("C is <%s>\n", textures->c);
	}
}

void	textures_null(t_textures *textures)
{
	textures->no = NULL;
	textures->so = NULL;
	textures->ea = NULL;
	textures->we = NULL;
	textures->f = NULL;
	textures->c = NULL;
	textures->f_color = NULL;
	textures->c_color = NULL;
}
