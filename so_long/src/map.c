/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:47:56 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/19 23:17:20 by smonte-e         ###   ########.fr       */
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
		ft_printf("map: %s\n", str);
//		char_to_sprite(data, str);
		free(str);
	}
	close(fd);
}

void sprite_init(t_data data)
{
	int i;
	char *texture_files[] = {
	"../sprites/xpm/kaaris.xpm",
	"../sprites/xpm/harambe.xpm",
	"../sprites/xpm/tile01.xpm",
	"../sprites/xpm/tile02.xpm",
	"../sprites/xpm/tile03.xpm"
	};
	
	i = 0;
	data.width = 64;
	data.height = 64;
	while (i < 5) 
	{
		data.textures[i] = mlx_xpm_file_to_image(data.mlx_ptr, texture_files[i], &data.width, &data.height);
		data.addr[i] = mlx_get_data_addr(data.textures[i], &data.bits_per_pixel, &data.line_length, &data.endian);
		i++;
	}
}


void char_to_sprite(t_data data, char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		int texture_index;  // Index de la texture à utiliser
		switch (str[i]) {
			case '1':
				texture_index = 2;  // Index de la texture pour '1'
				break;
			case '0':
				texture_index = 3;  // Index de la texture pour '0'
				break;
			case 'P':
				texture_index = 0;  // Index de la texture pour 'P'
				break;
			case 'C':
				texture_index = 1;  // Index de la texture pour 'C'
				break;
			case 'E':
				texture_index = 4;  // Index de la texture pour 'E'
				break;
			default:
				// Gérer le cas par défaut (par exemple, caractère inconnu)
				texture_index = 0;
				break;
		}
		
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[texture_index], data.width, data.height);
		
		data.width += 64;
		i++;
	}
	data.height += 64;
}



