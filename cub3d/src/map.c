/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:31 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/08 11:11:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_init(int fd, t_cube *cube)
{
	int	i;
	int	j;

	cube->map = (t_map *)malloc(sizeof(t_map));
	if (cube->map == NULL)
		return ;
	i = -1;
	map_dim(fd, cube);
	cube->map->m_mini_map = (char **)malloc(cube->map->m_height
			* sizeof(char *));
	if (cube->map->m_mini_map == NULL)
	{
		free(cube->map);
		cube->map = NULL;
		return ;
	}
	while (++i < cube->map->m_height)
	{
		j = -1;
		cube->map->m_mini_map[i] = (char *)malloc((cube->map->m_width + 1)
				* sizeof(char));
		if (cube->map->m_mini_map[i] == NULL)
		{
			free(cube->map->m_mini_map);
			free(cube->map);
			cube->map = NULL;
			return ;
		}
		while (++j < cube->map->m_width)
			cube->map->m_mini_map[i][j] = '@';
		cube->map->m_mini_map[i][j] = '\0';
	}
}

void	map_dim(int fd, t_cube *cube)
{
	int		y;
	int		max_width;
	int		line_width;
	char	*buff;

	y = 0;
	max_width = 0;
	cube->map->m_width = 0;
	cube->map->m_height = 0;
	while (true)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		y++;
		line_width = ft_strlen(buff);
		if (line_width > max_width)
			max_width = line_width;
		free(buff);
	}
	cube->map->m_height = y;
	cube->map->m_width = max_width - 1;
}

void	map_to_tab(int fd, t_cube *cube)
{
	char	*buff;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = MAP_LINE;
	printf(BLU"\n----------- MINI MAP -----------\n\n"RST);
	while (++i <= MAP_LINE)
		buff = get_next_line(fd);
	while (y < cube->map->m_height)
	{
		buff = get_next_line(fd);
		x = 0;
		while (buff[x] != '\n' && buff[x] != '\0')
		{
			cube->map->m_mini_map[y][x] = buff[x];
			printf(BLU"%c"RST, cube->map->m_mini_map[y][x]);
			x++;
		}
		y++;
		printf("\n");
		free(buff);
	}
	printf("\n");
}

void	map_renderer_init(t_cube *cube, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(RED "Error\nLa carte est introvable.\n" RST, 2);
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(".cub", argv[1] + (ft_strlen(argv[1]) - 4), 4) != 0)
	{
		ft_putstr_fd(RED "Error\nLa carte est au mauvais format.\n" RST, 2);
		exit(EXIT_FAILURE);
	}
	map_init(fd, cube);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_to_tab(fd, cube);
	close(fd);
}
