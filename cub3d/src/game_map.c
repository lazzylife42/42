/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:49:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/07 16:15:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_wall(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < Y_RES)
	{
		x = 0;
		while (x < X_RES)
		{
			printf("%d", cube->map->m_wall[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	init_player(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	cube->map->player = (t_player *)malloc(sizeof(t_player));
	init_wall(cube);
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == 'P')
			{
				cube->map->player->p_pos_x = x * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_y = y * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_a = 180;
				cube->map->player->offset = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	fill_m_wall(t_cube *cube, int px, int py)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI_SCALE)
	{
		x = 0;
		while (x < MINI_SCALE)
		{
			cube->map->m_wall[y + py][x + px] = 1;
			x++;
		}
		y++;
	}
}

void	init_wall(t_cube *cube)
{
	int	x;
	int	y;

	y = -1;
	while (++y < Y_RES)
	{
		x = -1;
		while (++x < X_RES)
			cube->map->m_wall[y][x] = 0;
	}
	y = -1;
	while (++y < cube->map->m_height)
	{
		x = -1;
		while (++x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == '1')
				fill_m_wall(cube, x * MINI_SCALE, y * MINI_SCALE);
		}
	}
}
