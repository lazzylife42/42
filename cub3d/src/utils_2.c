/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:05:51 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 18:18:02 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_textures(char *tmp, t_textures *textures, int *found)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0)
	{
		textures->no = remove_backslash(tmp + 3);
		found[0]++;
	}
	if (ft_strncmp(tmp, "SO ", 3) == 0)
	{
		textures->so = remove_backslash(tmp + 3);
		found[1]++;
	}
	if (ft_strncmp(tmp, "EA ", 3) == 0)
	{
		textures->ea = remove_backslash(tmp + 3);
		found[2]++;
	}
	if (ft_strncmp(tmp, "WE ", 3) == 0)
	{
		textures->we = remove_backslash(tmp + 3);
		found[3]++;
	}
	if (found[0] == 0 && found[1] == 0 && found[2] == 0 && found[3] == 0 && found[4] == 0 && found[5] == 0)
		ft_error(RED "Error\nMap not last or invalid file\n" RST);
}

void	find_colors(char *tmp, t_textures *textures, int *found)
{
	if (ft_strncmp(tmp, "F ", 2) == 0)
	{
		textures->f = remove_backslash(tmp + 2);
		found[4]++;
	}
	if (ft_strncmp(tmp, "C ", 2) == 0)
	{
		textures->c = remove_backslash(tmp + 2);
		found[5]++;
	}
}

void	find_cardinal(int fd, t_textures *textures)
{
	char	*tmp;
	int		i;
	int		found[6];

	i = 0;
	assign_array(i, found);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		find_textures(tmp, textures, found);
		find_colors(tmp, textures, found);
		i = 0;
		check_duplicates(i, found);
		tmp = get_next_line(fd);
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
