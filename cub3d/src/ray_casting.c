/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:35:00 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/21 15:04:18 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_vecf	raycast(t_cube *cube)
// {
// 	int		fov;
// 	float	ra;
// 	float	a_tan;
// 	float   dx, dy;
// 	float   sdx, sdy;
// 	t_vecf	ray;

// 	ray.x = cube->map->player->p_pos_x;
//     ray.y = cube->map->player->p_pos_y;
// 	ra = (cube->map->player->p_pos_a - 90) * M_PI / 180;

// 	return (ray);
// }

void	draw_wall(t_cube *cube)
{
	int		color;
	int		ratio;
	int		side;
	int		col;
	int		hit;
	float	ra;
	float	p_walld;
	t_vecf	map;
	t_vecf	dir;
	t_vecf	step;
	t_vecf	sided;
	t_vecf	delta;

	ra = (cube->map->player->p_pos_a - 90) * M_PI / 180;
	col = 0;
	while (col < X_RES)
	{
		ratio = ((col - X_RES / 2) / (float)X_RES) * MINI_SCALE;
		dir.x = (cos(ra) / 2 + (cos(ra - 0.25 )) * ratio);
		dir.y = (sin(ra) / 2 + (sin(ra - 0.25 )) * ratio);
		map.x = floor(cube->map->player->p_pos_x);
		map.y = floor(cube->map->player->p_pos_y);
		delta.x = sqrt(1 + ((dir.y * dir.y) / (dir.x * dir.x)));
		delta.y = sqrt(1 + ((dir.x * dir.x) / (dir.y * dir.y)));
		if (dir.x < 0)
		{
			step.x = -1;
			sided.x = (cube->map->player->p_pos_x - map.x) * delta.x;
		}
		else
		{
			step.x = 1;
			sided.x = (map.x + 1 - cube->map->player->p_pos_x) * delta.x;
		}
		if (dir.y < 0)
		{
			step.y = -1;
			sided.y = (cube->map->player->p_pos_y - map.y) * delta.y;
		}
		else
		{
			step.y = 1;
			sided.y = (map.y + 1 - cube->map->player->p_pos_y) * delta.y;
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
			if (cube->map->m_mini_map[(int)map.y / MINI_SCALE][(int)map.x
				/ MINI_SCALE] == '1')
				hit = 1;
		}
		if (side == 0)
			p_walld = (map.x - cube->map->player->p_pos_x + (1 - step.x) / 2)
				/ dir.x * MINI_SCALE;
		else
			p_walld = (map.y - cube->map->player->p_pos_y + (1 - step.y) / 2)
				/ dir.y * MINI_SCALE;
		if (side == 0)
			color = 0x808080;
		else
			color = 0xFFFFFF;
		draw_line(cube->img, (t_vec){col, (X_RES / 2) - (X_RES / 4) / p_walld * 2 * MINI_SCALE},
			(t_vec){col, (X_RES / 2) + (X_RES / 4) / p_walld * 2 * MINI_SCALE}, color);
		col++;
	}
}
