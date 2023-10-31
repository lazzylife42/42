/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:47:56 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/31 16:59:27 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(int fd, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	map_dim(fd, data);
	data->map = (char **)malloc(data->map_height * sizeof(char *));
	while (i < data->map_height)
	{
		data->map[i] = (char *)malloc(data->map_width * sizeof(char));
		j = 0;
		while (j < data->map_width)
		{
			data->map[i][j] = '#';
			j++;
		}
		i++;
	}
}

void	map_dim(int fd, t_data *data)
{
	int		y;
	size_t	check;
	char	*buff;

	y = 0;
	check = 0;
	data->map_width = 0;
	data->map_height = 0;
	while ((buff = get_next_line(fd)))
	{
		y++;
		check = ft_strlen(buff);
		free(buff);
	}
	data->map_height = y;
	data->map_width = check;
}

void	map_to_tab(int fd, t_data *data)
{
	char	*buff;
	int		x;
	int		y;

	y = 0;
	while (y < data->map_height)
	{
		buff = get_next_line(fd);
		x = 0;
		while (buff[x] != '\n' && buff[x] != '\0')
		{
			data->map[y][x] = buff[x];
			ft_printf("[%c]", data->map[y][x]);
			x++;
		}
		y++;
		ft_printf("\n");
		free(buff);
	}
}

void	map_renderer_init(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nErreur lors de l'ouverture du fichier de carte.\n");
		exit(EXIT_FAILURE);
	}
	map_init(fd, data);
	map_sprit_init(data);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_to_tab(fd, data);
	close(fd);
}

void	map_sprit_init(t_data *data)
{
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/kaaris.xpm", &data->width, &data->height);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/harambe.xpm", &data->width, &data->height);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/tile01.xpm", &data->width, &data->height);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/tile02.xpm", &data->width, &data->height);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/tile03.xpm", &data->width, &data->height);
	data->textures[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/booba.xpm", &data->width, &data->height);
}
