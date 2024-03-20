/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 04:07:34 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/09 15:29:05 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_front(t_cube *cube)
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
	if (cube->map->m_wall[next_y][next_x] != 1)
	{
		cube->map->player->p_pos_y += (MINI_SCALE / FINE_RATIO) * sin_angle;
		cube->map->player->p_pos_x += (MINI_SCALE / FINE_RATIO) * cos_angle;
	}
}

void	move_back(t_cube *cube)
{
	int		next_x;
	int		next_y;
	float	angle_rad;
	float	sin_angle;
	float	cos_angle;

	angle_rad = (cube->map->player->p_pos_a + 90) * M_PI / 180.0;
	sin_angle = sin(angle_rad);
	cos_angle = cos(angle_rad);
	next_x = (MINI_SCALE / FINE_RATIO) * cos_angle + cube->map->player->p_pos_x;
	next_y = (MINI_SCALE / FINE_RATIO) * sin_angle + cube->map->player->p_pos_y;
	if (cube->map->m_wall[next_y][next_x] != 1)
	{
		cube->map->player->p_pos_y += (MINI_SCALE / FINE_RATIO) * sin_angle;
		cube->map->player->p_pos_x += (MINI_SCALE / FINE_RATIO) * cos_angle;
	}
}

void	move_left(t_cube *cube)
{
	float	angle_rad;
	float	sin_angle;
	float	cos_angle;
	float	next_x;
	float	next_y;

	angle_rad = (cube->map->player->p_pos_a + 90) * M_PI / 180.0;
	sin_angle = sin(angle_rad + M_PI_2);
	cos_angle = cos(angle_rad + M_PI_2);
	next_x = cube->map->player->p_pos_x + (MINI_SCALE / FINE_RATIO) * cos_angle;
	next_y = cube->map->player->p_pos_y + (MINI_SCALE / FINE_RATIO) * sin_angle;
	if (cube->map->m_wall[(int)next_y][(int)next_x] != 1)
	{
		cube->map->player->p_pos_x = next_x;
		cube->map->player->p_pos_y = next_y;
	}
}

void	move_right(t_cube *cube)
{
	float	angle_rad;
	float	sin_angle;
	float	cos_angle;
	float	next_x;
	float	next_y;

	angle_rad = (cube->map->player->p_pos_a + 270) * M_PI / 180.0;
	sin_angle = sin(angle_rad - M_PI_2 + M_PI);
	cos_angle = cos(angle_rad - M_PI_2 + M_PI);
	next_x = cube->map->player->p_pos_x + (MINI_SCALE / FINE_RATIO) * cos_angle;
	next_y = cube->map->player->p_pos_y + (MINI_SCALE / FINE_RATIO) * sin_angle;
	if (cube->map->m_wall[(int)next_y][(int)next_x] != 1)
	{
		cube->map->player->p_pos_x = next_x;
		cube->map->player->p_pos_y = next_y;
	}
}
