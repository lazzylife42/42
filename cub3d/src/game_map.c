/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:49:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/13 17:09:54 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_map_height(t_map *map, char *arg)
{
	int	valid_count;
	int	total_lines;

	valid_count = count_valid_map_lines(arg);
	if (valid_count == 0)
		ft_error(RED "Error\nMap missing\n" RST);
	else if (valid_count < 3)
		ft_error(RED "Error\nMap too small\n" RST);
	total_lines = count_total_lines(arg);
	map->m_height = valid_count;
	map->file_height = total_lines;
}

void	get_map_width(t_map *map, char *arg)
{
	int	fd;
	int	map_start;
	int	longest_line_width;

	map_start = map->file_height - map->m_height;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	skip_lines_before_map(fd, map_start);
	longest_line_width = calculate_longest_line_width(fd, map->m_height);
	map->m_width = longest_line_width;
	close(fd);
}

int	set_map(char *arg, char **argv, t_cube *cube)
{
	get_map_height(cube->map, arg);
	get_map_width(cube->map, arg);
	map_renderer_init(cube, argv);
	return (0);
}

void	init_player(t_cube *cube)
{
	int	x;
	int	y;
	int	current_char;

	y = 0;
	cube->map->player = allocate_mem_player(cube);
	error_players(cube);
	init_wall(cube);
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			current_char = cube->map->m_mini_map[y][x];
			if (current_char == 'N' || current_char == 'E'
				|| current_char == 'S' || current_char == 'W')
			{
				set_player_position(cube, x, y, current_char);
				return ;
			}
			x++;
		}
		y++;
	}
}
