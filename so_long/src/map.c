/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:47:56 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/24 18:58:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(int fd, t_data *data)
{
	int i;
	int j;
		
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

void map_dim(int fd, t_data *data)
{
	int y;
	char *buff;

	y = 0;
	data->map_width = 0;
	data->map_height = 0;
	while ((buff = get_next_line(fd)))
	{
		y++;
		data->map_width = ft_strlen(buff);
		free(buff);
	}
	data->map_height = y;
}

void map_to_tab(int fd, t_data *data)
{
	char *buff;
	int x;
	int y;

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
	int fd;

	fd = open(argv[1], O_RDONLY);
	map_init(fd, data);
	map_sprit_init(data);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_to_tab(fd, data);
	close(fd);
}

void	map_sprit_init(t_data *data)
{
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/kaaris.xpm", &data->width, &data->height);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/harambe.xpm", &data->width, &data->height);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/tile01.xpm", &data->width, &data->height);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/tile02.xpm", &data->width, &data->height);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/tile03.xpm", &data->width, &data->height);
}

void	map_renderer(t_data *data)
{
	int x;
	int y;
	int texture_index;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			switch (data->map[y][x])
			{
				case '1':
					texture_index = 2;
					break;
				case '0':
					texture_index = 3;
					break;
				case 'P':
					texture_index = 0;
					break;
				case 'C':
					texture_index = 1;
					break;
				case 'E':
					texture_index = 4;
					break;
			}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[texture_index], x * 64, y * 64);
		x++;			
		}
	y++;
	}
}

void free_map(t_data *data)
{
	int i = 0;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
}


/*
	data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/kaaris.xpm", &data.width, &data.height);
	data.textures[1] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/harambe.xpm", &data.width, &data.height);
    data.textures[2] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile01.xpm", &data.width, &data.height);
    data.textures[3] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile02.xpm", &data.width, &data.height);
    data.textures[4] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile03.xpm", &data.width, &data.height);
*///	map_renderer(&data, &argv[1]);

/*	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], 64, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[2], 128, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[3], 192, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[4], 256, 0);
*/	