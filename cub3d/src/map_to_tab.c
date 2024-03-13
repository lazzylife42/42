/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:54:32 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 18:17:01 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	skip_empty_or_single_char_lines(char *buff)
{
	if (ft_strlen(buff) == 1)
		return (1);
	if (is_part_of_map(buff) == -1 && ft_is_empty(buff) == 1)
	{
		free(buff);
		return (1);
	}
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	return (fd);
}

void	print_mini_map_header(void)
{
	ft_printf(BLU "\n----------- MINI MAP -----------\n\n" RST);
}

void	store_map_line(t_cube *cube, int i, char *buff)
{
	ft_strlcpy(cube->map->m_mini_map[i], buff, ft_strlen(buff));
	free(buff);
}

void	check_map_last_or_invalid(char *buff, int map_encountered)
{
	if (map_encountered)
	{
		ft_error(RED "Error\nMap not last or invalid file\n" RST);
		free(buff);
		return ;
	}
}

void	read_and_store_map(int fd, t_cube *cube)
{
	char	*buff;
	int		i;
	int		map_encountered;
	int		texture_encountered;
	int		color_encountered;

	i = 0;
	map_encountered = 0;
	texture_encountered = 0;
	color_encountered = 0;
	buff = get_next_line(fd);
	if (is_part_of_map(buff) != -1)
		ft_error(RED "Error\nMap not last\n" RST);
	while (buff != NULL)
	{
		if (skip_empty_or_single_char_lines(buff))
		{
			check_map_last_or_invalid(buff, map_encountered);
			buff = get_next_line(fd);
			continue ;
		}
		if (!check_valid_chars_in_line(buff))
		{
			handle_invalid_char(buff);
			buff = get_next_line(fd);
			continue ;
		}
		if (is_part_of_map(buff) != -1)
			map_encountered = 1;
		store_map_line(cube, i, buff);
		if (DEBUG == 1)
			ft_printf(BLU "%s\n" RST, cube->map->m_mini_map[i]);
			i++;
		buff = get_next_line(fd);
	}
	free(buff);
}
