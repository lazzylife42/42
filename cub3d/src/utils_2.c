/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:05:51 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/18 14:01:03 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*remove_spaces_and_prefix(char *tmp, char *texture, int trim_nbr)
{
	char	*trimmed;

	texture = remove_backslash(tmp + trim_nbr);
	texture = trim_spaces(texture);
	trimmed = (char *)malloc(ft_strlen(texture) + 1);
	ft_strlcpy(trimmed, texture, ft_strlen(texture) + 1);
	return (trimmed);
}

void	find_textures(char *tmp, t_textures *textures)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0 && textures->no == NULL)
		textures->no = remove_spaces_and_prefix(tmp, textures->no, 3);
	if (ft_strncmp(tmp, "SO ", 3) == 0 && textures->so == NULL)
		textures->so = remove_spaces_and_prefix(tmp, textures->so, 3);
	if (ft_strncmp(tmp, "EA ", 3) == 0 && textures->ea == NULL)
		textures->ea = remove_spaces_and_prefix(tmp, textures->ea, 3);
	if (ft_strncmp(tmp, "WE ", 3) == 0 && textures->we == NULL)
		textures->we = remove_spaces_and_prefix(tmp, textures->we, 3);
	if (ft_strncmp(tmp, "F ", 2) == 0)
		textures->f = remove_spaces_and_prefix(tmp, textures->f, 2);
	if (ft_strncmp(tmp, "C ", 2) == 0)
		textures->c = remove_spaces_and_prefix(tmp, textures->c, 2);
}

void	textures_and_colors_valid(int t, int c, t_textures *textures)
{
	if (t <= 0 && c <= 0)
		error_wrapper(textures, RED "Error\nThere is only a map...\n" RST);
	else if (t < 4)
		error_wrapper(textures, RED "Error\nMissing textures\n" RST);
	else if (c < 2)
		error_wrapper(textures, RED "Error\nMissing colors\n" RST);
	else if (t > 4 || c > 2)
		error_wrapper(textures, RED "Error\nToo many colors/textures\n" RST);
}

void	find_cardinal(int fd, t_textures *textures)
{
	char	*tmp;
	int		c;
	int		t;

	c = 0;
	t = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (has_textures(tmp) == 1)
			t++;
		if (has_colors(tmp) == 1)
			c++;
		find_textures(tmp, textures);
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
	free(tmp);
	textures_and_colors_valid(t, c, textures);
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
