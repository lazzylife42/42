/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:31 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/13 11:00:19 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_delete(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < cube->map->m_height)
	{
		free(cube->map->m_mini_map);
		i++;
	}
	cube->map = NULL;
	free(cube->map);
}

void	map_to_tab(char *file, t_cube *cube)
{
	int	fd;

	fd = open_file(file);
	print_mini_map_header();
	read_and_store_map(fd, cube);
	close(fd);
}

void	map_renderer_init(t_cube *cube, char **argv)
{
	(void)argv;
	map_init(cube);
	map_to_tab(argv[1], cube);
	if (is_within_walls(cube->map->m_mini_map, cube) == -1)
		ft_error(RED "Error\nMap is not closed\n" RST);
	else
	{
		printf(MAG "Map passed !\n" RST);
		printf("\n");
	}
}
