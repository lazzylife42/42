/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:23:56 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/12 14:03:08 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int		len;	

	new_tmp = ft_strdup(tmp + 3);
	if (ft_strchr(new_tmp, '\n') != NULL)
	{
		len = ft_strlen(new_tmp);
		new_tmp[len - 1] = '\0';
		return (ft_strdup(new_tmp));
	}
	return (NULL);
}

char	*remove_backslash_2(char *tmp)
{
	char	*new_tmp;
	int		len;	

	new_tmp = ft_strdup(tmp + 2);
	if (ft_strchr(new_tmp, '\n') != NULL)
	{
		len = ft_strlen(new_tmp);
		new_tmp[len - 1] = '\0';
		return (ft_strdup(new_tmp));
	}
	return (NULL);
}

void	check_map_pos(char *tmp)
{
	if (ft_strncmp(tmp, " ", 1) == 0
		|| ft_strncmp(tmp, "1", 1) == 0
		|| ft_strncmp(tmp, "0", 1) == 0)
		ft_error(RED "Error\nMap should be last position\n" RST);
}

void	find_cardinal(int fd, t_textures *textures)
{
	char		*tmp;

	tmp = get_next_line(fd);
	check_map_pos(tmp);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp, "NO ", 3) == 0)
			textures->no = remove_backslash(tmp);
		if (ft_strncmp(tmp, "SO ", 3) == 0)
			textures->so = remove_backslash(tmp);
		if (ft_strncmp(tmp, "EA ", 3) == 0)
			textures->ea = remove_backslash(tmp);
		if (ft_strncmp(tmp, "WE ", 3) == 0)
			textures->we = remove_backslash(tmp);
		if (ft_strncmp(tmp, "F ", 2) == 0)
			textures->f = remove_backslash_2(tmp);
		if (ft_strncmp(tmp, "C ", 2) == 0)
			textures->c = remove_backslash_2(tmp);
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
}
