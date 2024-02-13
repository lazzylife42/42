/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:59:05 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 18:36:17 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_move(int keysym, t_cube *data)
{
	if (keysym == 53)
		on_destroy(data);
	else if (keysym == 13 || keysym == 126)
		move_up(data);
	else if (keysym == 0 || keysym == 123)
		move_left(data);
	else if (keysym == 1 || keysym == 125)
		move_down(data);
	else if (keysym == 2 || keysym == 124)
		move_right(data);

	// map_renderer(data);
	// game_state(data);
	return (0);
}

void	move_up(t_cube *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->m_height)
	{
		x = 0;
		while (x < data->map->m_width)
		{
			if (data->map->m_mini_map[y][x] == 'P' && data->map->m_mini_map[y - 1][x] != '1' && y > 1)
			{
				data->map->m_mini_map[y - 1][x] = 'P';
				data->map->m_mini_map[y][x] = '0';
				break ;
			}
			x++;
		}
		y++;
	}
}

void	move_left(t_cube *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->m_height)
	{
		x = 0;
		while (x < data->map->m_width)
		{
			if (data->map->m_mini_map[y][x] == 'P' && data->map->m_mini_map[y][x - 1] != '1' && x > 1)
			{
				data->map->m_mini_map[y][x - 1] = 'P';
				data->map->m_mini_map[y][x] = '0';
				break ;
			}
			x++;
		}
		y++;
	}
}

void	move_down(t_cube *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->m_height)
	{
		x = 0;
		while (x < data->map->m_width)
		{
			if (data->map->m_mini_map[y][x] == 'P' && y < data->map->m_height - 1
				&& data->map->m_mini_map[y + 1][x] != '1')
			{						
				data->map->m_mini_map[y + 1][x] = 'P';
				data->map->m_mini_map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_right(t_cube *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->m_height)
	{
		x = 0;
		while (x < data->map->m_width)
		{
			if (data->map->m_mini_map[y][x] == 'P' && x < data->map->m_width - 1
				&& data->map->m_mini_map[y][x + 1] != '1')
			{
				data->map->m_mini_map[y][x + 1] = 'P';
				data->map->m_mini_map[y][x] = '0';
				break ;
			}
			x++;
		}
		y++;
	}
}