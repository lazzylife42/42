/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:59:10 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/01 15:30:10 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	get_texture_index(char cell)
{
	if (cell == '1')
		return (2);
	else if (cell == '0')
		return (3);
	else if (cell == 'P')
		return (0);
	else if (cell == 'C')
		return (1);
	else if (cell == 'E')
		return (4);
	else if (cell == 'B')
		return (5);
	return (0);
}

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
			texture_index = get_texture_index(data->map[y][x]);
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
