/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:31 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/12 19:27:09 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_init(t_cube *cube)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = cube->map->m_width;
	height = cube->map->m_height;
	if (DEBUG == 1)
	{
		printf("Height is %d\n", height);
		printf("Width is %d\n", width);
	}
	cube->map->m_mini_map = (char **)malloc((height + 1)
			* sizeof(char *));
	if (cube->map->m_mini_map == NULL)
	{
		map_delete(cube);
		ft_error(RED "Error\nMalloc failed\n" RST);
	}
	while (i < height)
	{
		cube->map->m_mini_map[i] = (char *)malloc((width + 1)
				* sizeof(char));
		if (cube->map->m_mini_map[i] == NULL)
		{
			map_delete(cube);
			ft_error(RED "Error\nMalloc failed\n" RST);
		}
		ft_bzero(cube->map->m_mini_map[i], width);
		i++;
	}
}

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

int	is_part_of_map(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		if (buff[i] != '0' && buff[i] != '1'
			&& buff[i] != ' ' && buff[i] != 'N'
			&& buff[i] != 'E' && buff[i] != 'S'
			&& buff[i] != 'W' && buff[i] != 'D')
			return (-1);
		i++;
	}
	return (0);
}

void	map_to_tab(char *file, t_cube *cube)
{
	char	*buff;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	ft_printf(BLU "\n----------- MINI MAP -----------\n\n" RST);
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		if (ft_strlen(buff) == 1)
		{
			buff = get_next_line(fd);
			continue ;
		}
		if (is_part_of_map(buff) == -1 && ft_is_empty(buff) == 1)
		{
			buff = get_next_line(fd);
			continue ;
		}
		/* if (DEBUG == 1) */
		/* 	ft_printf("Y is %d:\n", y); */
		ft_strlcpy(cube->map->m_mini_map[i], buff, ft_strlen(buff));
		if (DEBUG == 1)
			ft_printf(BLU "%s\n" RST, cube->map->m_mini_map[i]);
		buff = get_next_line(fd);
		i++;
	}
	free(buff);
	buff = NULL;
	printf("\n");
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
	/* if (DEBUG == 1) */
	/* 	printf("is within walls : %d\n", is_within_walls(cube->map->m_mini_map, cube)); */
}
