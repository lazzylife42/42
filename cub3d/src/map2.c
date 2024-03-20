/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:55:52 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/15 18:59:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	frame_render(t_cube *cube)
{
	cube->img->img = mlx_new_image(cube->mlx_ptr, X_RES, Y_RES);
	cube->img->addr = mlx_get_data_addr(cube->img->img,
			&cube->img->bits_per_pixel, &cube->img->line_length,
			&cube->img->endian);
	map_renderer(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}

static void	player_render(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == 'N'
				|| cube->map->m_mini_map[y][x] == 'E'
				|| cube->map->m_mini_map[y][x] == 'W'
				|| cube->map->m_mini_map[y][x] == 'S')
				draw_triangle(cube);
			x++;
		}
		y++;
	}
}

static void	map_draw_square(t_cube *cube, int x, int y)
{
	if (cube->map->m_mini_map[y][x] == '1')
		draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
			MINI_SCALE - 2, 0x909090);
	else if (cube->map->m_mini_map[y][x] == '0'
		|| cube->map->m_mini_map[y][x] == 'P')
		draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
			MINI_SCALE - 2, 0xFFFFFF);
	else if (cube->map->m_mini_map[y][x] == 'D')
		draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
			MINI_SCALE - 2, 0xFF0000);
	else if (cube->map->m_mini_map[y][x] == 'd')
		draw_square(cube->img, (t_vec){x * MINI_SCALE, y * MINI_SCALE},
			MINI_SCALE - 2, 0x800080);
}

void	map_renderer(t_cube *cube)
{
	int	x;
	int	y;

	draw_rec(cube->img, (t_vec){0, 0}, (t_vec){X_RES, (Y_RES - HUD) / 2
		- cube->map->player->offset},
		rgb_to_hexa(cube->map->textures->c_color));
	draw_rec(cube->img, (t_vec){0, (Y_RES - HUD) / 2
		- cube->map->player->offset}, (t_vec){X_RES, (Y_RES - HUD)},
		rgb_to_hexa(cube->map->textures->f_color));
	draw_wall(cube);
	y = 0;
	while (cube->map->mini_map && y < cube->map->m_height)
	{
		x = 0;
		while (cube->map->mini_map && x < cube->map->m_width)
		{
			map_draw_square(cube, x, y);
			x++;
		}
		y++;
	}
	if (cube->map->mini_map)
		player_render(cube);
}
