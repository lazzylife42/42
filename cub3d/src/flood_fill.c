/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:13:22 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/15 18:56:22 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_flood_x(int flood_x[4])
{
	flood_x[0] = 1;
	flood_x[1] = -1;
	flood_x[2] = 0;
	flood_x[3] = 0;
}

void	init_flood_y(int flood_y[4])
{
	flood_y[0] = 0;
	flood_y[1] = 0;
	flood_y[2] = 1;
	flood_y[3] = -1;
}

void	replace_spaces(char *line)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(line) - 1;
	while (line[start] == ' ')
		start++;
	while (end >= 0 && line[end] == ' ')
		end--;
	i = 0;
	while (i < start)
	{
		line[i] = 'x';
		i++;
	}
	i = end + 1;
	while (i < ft_strlen(line))
	{
		line[i] = 'x';
		i++;
	}
}

void	flood_fill(char **map, t_cube *cube, int x, int y)
{
	int	width;
	int	height;
	int	i;
	int	flood_x[4];
	int	flood_y[4];

	i = 0;
	width = cube->map->m_width;
	height = cube->map->m_height;
	init_flood_x(flood_x);
	init_flood_y(flood_y);
	if (x < 0 || x >= width || y < 0 || y >= height
		|| map[y][x] == '1' || map[y][x] == 'D' || map[y][x] == '2')
		return ;
	if (map[y][x] == ' ')
		ft_error(RED "Error\nMap not closed\n" RST);
	if (map[y][x] == 'x')
		ft_error(RED "Error\nMap not closed\n" RST);
	map[y][x] = '2';
	while (i < 4)
	{
		flood_fill(map, cube, x + flood_x[i], y + flood_y[i]);
		i++;
	}
}
