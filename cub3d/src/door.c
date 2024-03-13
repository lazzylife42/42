/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:49:40 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/12 21:42:35 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_door(t_cube *cube)
{
	int		next_x;
	int		next_y;
	float	angle_rad;
	float	sin_angle;
	float	cos_angle;

	angle_rad = (cube->map->player->p_pos_a - 90) * M_PI / 180.0;
	sin_angle = sin(angle_rad);
	cos_angle = cos(angle_rad);
	next_x = cube->map->player->p_pos_x + (MINI_SCALE / FINE_RATIO) * cos_angle;
	next_y = cube->map->player->p_pos_y + (MINI_SCALE / FINE_RATIO) * sin_angle;
	if (cube->map->m_mini_map[next_y / MINI_SCALE][next_x / MINI_SCALE] == 'D')
	{
		if (cube->key->k_o == true)
			cube->map->m_mini_map[next_y
				/ MINI_SCALE][next_x / MINI_SCALE] = 'd';
	}
	else if (cube->map->m_mini_map[next_y
			/ MINI_SCALE][next_x / MINI_SCALE] == 'd')
	{
		if (cube->key->k_o == true)
			cube->map->m_mini_map[next_y
				/ MINI_SCALE][next_x / MINI_SCALE] = 'D';
	}
	init_wall(cube);
}
