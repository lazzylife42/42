/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:13:37 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 13:10:21 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_map_line(char *line)
{
	if (ft_strlen(line) == 1)
		return (0);
	if (is_part_of_map(line) == -1 && ft_is_empty(line) == 1)
		return (0);
	return (1);
}

int	count_total_lines(const char *file_path)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

int	count_valid_map_lines(char *file_path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_valid_map_line(line))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	skip_lines_before_map(int fd, int num_lines_to_skip)
{
	char	*line;
	int		lines_skipped;

	lines_skipped = 0;
	line = get_next_line(fd);
	while (lines_skipped < num_lines_to_skip && line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		lines_skipped++;
	}
	return (lines_skipped);
}

int	calculate_longest_line_width(int fd, int num_lines)
{
	char	*line;
	int		longest_width;
	int		line_width;
	int		i;

	i = 0;
	longest_width = 0;
	while (i < num_lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_width = ft_strlen_wo_spaces(line);
		if (line_width > longest_width)
			longest_width = line_width;
		free(line);
		i++;
	}
	return (longest_width);
}
