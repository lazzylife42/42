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
	if (cube->map->m_height < 1)
		ft_error(RED "Error\nNo map!\n" RST);
	if (map_start)
		cube->map->map_start = map_start;
}

int	get_map_height(t_cube *cube, char *arg, int height, int map_start)
{
	int		fd;
	char	*buff;
	int		counter;

	counter = 0;
	fd = open_file(arg);
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		if (ft_is_texture(buff) != 0 || ft_is_empty(buff))
			counter++;
		else
		{
			if (!map_start)
				map_start = counter;
			height++;
			counter++;
		}
		free(buff);
		buff = get_next_line(fd);
	}
	assign_heights(height, cube, map_start);
	free(buff);
	close(fd);
	return (counter);
}

void	assign_widths(t_cube *cube, int width)
{
	cube->map->m_width = width;
	if (cube->map->m_height == 2 && cube->map->m_width == 3)
		ft_error(RED "Error\nMap too small\n" RST);
}

char	*get_map_line_start_1(t_cube *cube, char *buff, int fd)
{
	int	j;

	j = 0;
	while (j++ < cube->map->map_start - 1)
	{
		buff = get_next_line(fd);
		free(buff);
		buff = NULL;
	}
	return (buff);
}

void	get_map_width(t_cube *cube, char *arg)
{
	int		fd;
	char	*buff;
	int		width;
	int		i;
	int		j;

	width = 0;
	buff = NULL;
	fd = open_file(arg);
	buff = get_map_line_start_1(cube, buff, fd);
	buff = get_next_line(fd);
	j = 0;
	while (j++ < cube->map->m_height)
	{
		i = 0;
		while (buff[i] != '\n' && buff[i] != '\0')
			i++;
		if (i > width)
			width = i;
		free(buff);
		buff = get_next_line(fd);
	}
	assign_widths(cube, width);
	free(buff);
	close(fd);
}
