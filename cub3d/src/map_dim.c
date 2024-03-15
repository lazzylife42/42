/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:13:37 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/14 15:42:24 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	assign_heights(int height, t_cube *cube, int map_start)
{
	cube->map->m_height = height;
	printf("Height is %d\n", cube->map->m_height);
	if (map_start)
		cube->map->map_start = map_start;
		printf("Map start is %d\n", cube->map->map_start);
}

void	get_map_height(t_cube *cube, char *arg)
{
	int		fd;
	char	*buff;
	int		height;
	int		map_start;
	int		counter;

	height = 0;
	map_start = 0;
	counter = 0;
	fd = open_file(arg);
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		if (ft_is_texture(buff) != 0 || ft_is_empty(buff))
		{
			counter++;
			buff = get_next_line(fd);
		}
		else
		{
			if (!map_start)
			{
				map_start = counter;
				height++;
				counter++;
			}
			buff = get_next_line(fd);
			counter++;
			height++;
		}
	}
	assign_heights(height, cube, map_start);
	free(buff);
	close(fd);
}

void	get_map_width(t_cube *cube, char *arg)
{
	int		fd;
	char	*buff;
	int		width;
	int		i;
	int		j;

	j = 0;
	width = 0;
	fd = open_file(arg);
	while (j++ < cube->map->map_start)
		buff = get_next_line(fd);
	j = 0;
	while (j < cube->map->m_height)
	{
		i = 0;
		while (buff[i] != '\n' && buff[i] != '\0')
			i++;
		if (i > width)
			width = i;
		buff = get_next_line(fd);
		j++;
	}
	cube->map->m_width = width;
	free(buff);
	close(fd);
}
