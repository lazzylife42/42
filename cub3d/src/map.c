/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:31 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 19:08:44 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_init(int fd, t_cube *data)
{
	int	i;
	int	j;

	data->map = (t_map *)malloc(sizeof(t_map));
	if (data->map == NULL)
		return ;
	i = -1;
	map_dim(fd, data);
	data->map->m_mini_map = (char **)malloc(data->map->m_height
			* sizeof(char *));
	if (data->map->m_mini_map == NULL)
	{
		free(data->map);
		data->map = NULL;
		return ;
	}
	while (++i < data->map->m_height)
	{
		j = -1;
		data->map->m_mini_map[i] = (char *)malloc((data->map->m_width + 1)
				* sizeof(char));
		if (data->map->m_mini_map[i] == NULL)
		{
			free(data->map->m_mini_map);
			free(data->map);
			data->map = NULL;
			return ;
		}
		while (++j < data->map->m_width)
			data->map->m_mini_map[i][j] = '@';
		data->map->m_mini_map[i][j] = '\0';
	}
}

void	map_dim(int fd, t_cube *data)
{
	int		y;
	int		max_width;
	int		line_width;
	char	*buff;

	y = 0;
	max_width = 0;
	data->map->m_width = 0;
	data->map->m_height = 0;
	while (TRUE)
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
	data->map->m_height = y;
	data->map->m_width = max_width - 1;
}

void	map_to_tab(int fd, t_cube *data)
{
	char	*buff;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = MAP_LINE;
	while (++i <= MAP_LINE)
		buff = get_next_line(fd);
	while (y < data->map->m_height)
	{
		buff = get_next_line(fd);
		x = 0;
		while (buff[x] != '\n' && buff[x] != '\0')
		{
			data->map->m_mini_map[y][x] = buff[x];
			ft_printf(BLU"%c"RST, data->map->m_mini_map[y][x]);
			x++;
		}
		y++;
		ft_printf("\n");
		free(buff);
	}
	ft_printf("\n");
}

void	map_renderer_init(t_cube *data, char **argv)
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
	map_init(fd, data);
	// map_sprit_init(data);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_to_tab(fd, data);
	close(fd);
}

// void	map_sprit_init(t_cube *data)
// {
// 	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, TEX_FLOOR,
// 			&data->width, &data->height);
// 	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/tile03.xpm",
// 			&data->width, &data->height);
// 	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, TEX_WALL,
// 			&data->width, &data->height);
// 	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, TEX_PLAYER,
// 			&data->width, &data->height);
// 	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/tile03.xpm",
// 			&data->width, &data->height);
// 	data->textures[5] = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/tile03.xpm",
// 			&data->width, &data->height);
// }
