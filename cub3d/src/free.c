/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/19 21:58:29 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_textures(t_textures *textures)
{
	if (textures->no)
		free(textures->no);
	if (textures->so)
		free(textures->so);
	if (textures->ea)
		free(textures->ea);
	if (textures->we)
		free(textures->we);
	if (textures->f)
		free(textures->f);
	if (textures->c)
		free(textures->c);
	if (textures->f_color)
		free(textures->f_color);
	if (textures->c_color)
		free(textures->c_color);
	free(textures);
	textures = NULL;
}

void	free_map(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < cube->map->m_height)
	{
		free(cube->map->m_mini_map[i]);
		i++;
	}
	free(cube->map->m_mini_map);
	free(cube->text->t_img);
	free(cube->text);
	free(cube->map->player);
	free(cube->map);
	cube->map = NULL;
	cube = NULL;
}

void	error_wrapper(t_textures *textures, char *error)
{
	free_textures(textures);
	ft_error(error);
}

void	free_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		free(colors[i]);
		i++;
	}
	free(colors);
}

char	*get_map_line_start_2(t_cube *cube, char *buff, int fd)
{
	int	j;

	j = -1;
	while (j++ < cube->map->map_start - 1)
	{
		buff = get_next_line(fd);
		free(buff);
	}
	return (buff);
}
