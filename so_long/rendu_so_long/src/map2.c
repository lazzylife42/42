/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:59:10 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/31 22:16:48 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_renderer(t_data *data)
{
	int	x;
	int	y;
	int	texture_index;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == '1')
				texture_index = 2;
			else if (data->map[y][x] == '0')
				texture_index = 3;
			else if (data->map[y][x] == 'P')
				texture_index = 0;
			else if (data->map[y][x] == 'C')
				texture_index = 1;
			else if (data->map[y][x] == 'E')
				texture_index = 4;
			else if (data->map[y][x] == 'B')
				texture_index = 5;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->textures[texture_index], x * 64, y * 64);
			x++;
		}
		y++;
	}
	move_booba(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 23, 19,
		0xffffff, ft_itoa(data->moves));
}

void	free_sprite(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(data->win_ptr, data->textures[i]);
		i++;
	}
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
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
