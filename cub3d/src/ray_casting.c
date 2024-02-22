/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:35:00 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/22 12:44:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_cube *cube)
{
	int		color;
	int		side;
	int		col;
	int		hit;
	double	ra;
	double	p_walld;
	double	ratio;
	t_vecf	map;
	t_vecf	dir;
	t_vecf	step;
	t_vecf	sided;
	t_vecf	delta;

	col = 0;
	ra = (cube->map->player->p_pos_a - 90) * M_PI / 180;
	while (col < X_RES)
	{
		ratio = ((col * 2) / (double)X_RES) - 1;
		dir.x = (cos(ra + M_PI_2) * ratio) + cos(ra);
		dir.y = (sin(ra + M_PI_2) * ratio) + sin(ra);
		map.x = floor(cube->map->player->p_pos_x / MINI_SCALE);
		map.y = floor(cube->map->player->p_pos_y / MINI_SCALE);
		delta.x = fabs(1 / dir.x);
		delta.y = fabs(1 / dir.y);
		if (dir.x < 0)
		{
			step.x = -1;
			sided.x = ((cube->map->player->p_pos_x / MINI_SCALE) - map.x) * delta.x;
		}
		else
		{
			step.x = 1;
			sided.x = (map.x + 1 - (cube->map->player->p_pos_x / MINI_SCALE)) * delta.x;
		}
		if (dir.y < 0)
		{
			step.y = -1;
			sided.y = ((cube->map->player->p_pos_y / MINI_SCALE) - map.y) * delta.y;
		}
		else
		{
			step.y = 1;
			sided.y = (map.y + 1 - (cube->map->player->p_pos_y / MINI_SCALE)) * delta.y;
		}
		hit = 0;
		while (!hit)
		{
			if (sided.x < sided.y)
			{
				sided.x += delta.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				sided.y += delta.y;
				map.y += step.y;
				side = 1;
			}
			if (cube->map->m_mini_map[(int)map.y][(int)map.x] == '1')
				hit = 1;
		}
		if (side == 0)
			p_walld = sided.x - delta.x;
		else
			p_walld = sided.y - delta.y;
		if (side == 0)
			color = 0x808080;
		else
			color =	0x808080 / 2;
		double wall_height = Y_RES / p_walld;
		double wall_top = (Y_RES / 2) - (wall_height / 2);
		double wall_bottom = (Y_RES / 2) + (wall_height / 2);
		draw_line(cube->img, (t_vec){col, wall_top}, (t_vec){col, wall_bottom}, color);
		col++;
	}
}
