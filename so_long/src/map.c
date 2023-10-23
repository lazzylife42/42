/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:47:56 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/23 20:15:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_init(t_data *data, int width, int height)
{
    data->map_width = 64;
    data->map_height = 64;

    data->map = (int **)malloc(height * sizeof(int *));

    int i = 0;
    while (i < height)
    {
        data->map[i] = (int *)malloc(width * sizeof(int));

        int j = 0;
        while (j < width)
        {
            data->map[i][j] = 0; // Initialisation avec des valeurs par défaut (0)
            j++;
        }
        i++;
    }
}

void map_to_tab(int fd, t_data *data)
{
	char *buff;
	int i;
	int j;

	i = 0;
	while ((buff = get_next_line(fd)))
	{
		j = 0;
		while (buff[j])
		{
			data->map[i][j] = buff[j];
			ft_printf("[%c]", data->map[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
		free(buff);
	}
	data->map_width = j;
	data->map_height = i;
}

void map_to_str(t_data *data, char **argv)
{
	int fd;
//	char *str;
	
	fd = open(argv[1], O_RDONLY);
	map_sprit_init(data);
	map_init(data, 14, 5);
	map_to_tab(fd, data);
/*	while ((str = get_next_line(fd)))
	{
		ft_printf("map: %s", str);
		char_to_sprite(data, str);
		free(str);
	}
*/	close(fd);
}

void map_sprit_init(t_data *data)
{
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/kaaris.xpm", &data->width, &data->height);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/harambe.xpm", &data->width, &data->height);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/tile01.xpm", &data->width, &data->height);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/tile02.xpm", &data->width, &data->height);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/xpm/tile03.xpm", &data->width, &data->height);
}

void char_to_sprite(t_data *data, char *str)
{
	int x = 0;
	static int y = 0;
	int i = 0;
	int texture_index;

	while (str[i])
	{
		switch (str[i]) {
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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[texture_index], x, y);
		x += 64;
		i++;
	}
	y += 64;
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
