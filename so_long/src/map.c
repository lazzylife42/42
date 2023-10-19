/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:47:56 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/20 01:52:35 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>

void map_to_str(t_data data)
{
	int fd;
	char *str;

	sprite_init(data);
	fd = open("map/level1.ber", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		ft_printf("map: %s", str);
		char_to_sprite(data, str);
		free(str);
	}
	close(fd);
}

void sprite_init(t_data data)
{
	data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/kaaris.xpm", &data.width, &data.height);
	data.textures[1] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/harambe.xpm", &data.width, &data.height);
    data.textures[2] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile01.xpm", &data.width, &data.height);
    data.textures[3] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile02.xpm", &data.width, &data.height);
    data.textures[4] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile03.xpm", &data.width, &data.height);
}


void char_to_sprite(t_data data, char *str)
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
        mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[texture_index], x, y);
        x += 64;
        i++;
    }
	y += 64;
}





