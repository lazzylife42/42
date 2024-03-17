/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:54:32 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/17 18:31:02 by smonte-e         ###   ########.fr       */
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

void	print_mini_map_header(void)
{
	ft_printf(BLU "\n----------- MINI MAP -----------\n\n" RST);
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
			ft_error(RED "Error\nMem alloc failed\n" RST);
		ft_strcpy(resized_str, str);
		ft_memset(resized_str + old_length, ' ', new_length - old_length);
		resized_str[new_length] = '\0';
		ft_strlcpy(str, resized_str, new_length);
	}
}

void	store_map_line(t_cube *cube, int i, char *buff)
{
	if (buff[ft_strlen(buff) -1] == '\n')
		ft_strlcpy(cube->map->m_mini_map[i], buff, ft_strlen(buff));
	else
		ft_strlcpy(cube->map->m_mini_map[i], buff, ft_strlen(buff) + 1);
	resize_string(cube->map->m_mini_map[i], cube->map->m_width);
	replace_spaces(cube->map->m_mini_map[i]);
	free(buff);
}

void	read_and_store_map(int fd, t_cube *cube)
{
	char	*buff;
	int		i;
	int		j;
	// int		map_encountered;

	i = 0;
	j = -1;
	while (j++ < cube->map->map_start)
		buff = get_next_line(fd);
	while (buff != NULL)
	{
		if (!check_valid_chars_in_line(buff))
		{
			handle_invalid_char(buff);
			buff = get_next_line(fd);
			continue ;
		}
		// if (ft_is_texture(buff) == 0 || !ft_is_empty(buff))
		// 	map_encountered = 1;
		store_map_line(cube, i, buff);
		if (DEBUG == 1)
			ft_printf(BLU "%s\n" RST, cube->map->m_mini_map[i]);
		i++;
		buff = get_next_line(fd);
	}
	free(buff);
}
