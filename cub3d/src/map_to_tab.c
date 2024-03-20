/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:54:32 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/14 15:51:20 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	return (fd);
}

void	resize_string(char *str, size_t new_length)
{
	size_t	old_length;
	char	*resized_str;

	old_length = ft_strlen(str);
	if (new_length > old_length)
	{
		resized_str = malloc(new_length + 1);
		if (resized_str == NULL)
			ft_error(RED "Error\nMalloc failed\n" RST);
		ft_strcpy(resized_str, str);
		ft_memset(resized_str + old_length, ' ', new_length - old_length);
		resized_str[new_length] = '\0';
		ft_strlcpy(str, resized_str, new_length);
		free(resized_str);
	}
}

void	store_map_line(t_cube *cube, int i, char *buff)
{
	ft_strlcpy(cube->map->m_mini_map[i], buff, ft_strlen(buff));
	resize_string(cube->map->m_mini_map[i], cube->map->m_width);
	replace_spaces(cube->map->m_mini_map[i]);
	if (check_ea_we(cube->map->m_mini_map[i]) == -1)
		ft_error(RED "Error\nMap not closed ea/we\n" RST);
	free(buff);
	buff = NULL;
}

void	check_first_and_last_line(t_cube *cube, int i)
{
	if (check_line(cube->map->m_mini_map[0]) == -1
		&& check_line(cube->map->m_mini_map[i - 1]) == 0)
		ft_error(RED "Map not closed no/so\n" RST);
}

void	read_and_store_map(int fd, t_cube *cube)
{
	char	*buff;
	int		i;

	i = 0;
	buff = NULL;
	buff = get_map_line_start_2(cube, buff, fd);
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		buff = has_invalid(fd, buff);
		if (ft_is_empty(buff))
		{
			free(buff);
			buff = NULL;
			buff = get_next_line(fd);
			continue ;
		}
		store_map_line(cube, i, buff);
		i++;
		buff = get_next_line(fd);
	}
	check_first_and_last_line(cube, i);
	free(buff);
}
