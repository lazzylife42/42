/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:11:01 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 09:12:14 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

static void	fill_m_wall(t_cube *cube, int px, int py, bool door)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI_SCALE)
	{
		x = 0;
		while (x < MINI_SCALE)
		{
			if (door)
				cube->map->m_wall[y + py][x + px] = 1;
			else
				cube->map->m_wall[y + py][x + px] = 0;
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
			if (cube->map->m_mini_map[y][x] == '1'
					|| cube->map->m_mini_map[y][x] == 'D')
				fill_m_wall(cube, x * MINI_SCALE, y * MINI_SCALE, true);
			else if (cube->map->m_mini_map[y][x] == 'd')
				fill_m_wall(cube, x * MINI_SCALE, y * MINI_SCALE, false);
		}
	}
}
