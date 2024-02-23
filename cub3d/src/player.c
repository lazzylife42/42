/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:59:05 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/24 00:07:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_cube *cube)
{
	cube->map->player->p_pos_a -= 90 / FINE_RATIO / ROT_RATIO;
	if (cube->map->player->p_pos_a % 360 == 0)
		cube->map->player->p_pos_a += 360;
}


void	rotate_right(t_cube *cube)
{
	cube->map->player->p_pos_a += 90 / FINE_RATIO / ROT_RATIO;
	if (cube->map->player->p_pos_a % 360 == 0)
		cube->map->player->p_pos_a -= 360;
}

void rotate_up(t_cube *cube)
{
    double increment = MINI_SCALE / FINE_RATIO * X_RATIO;
    double max_offset = Y_RES / 2 - MINI_SCALE;
    if (cube->map->player->offset - increment <= -max_offset)
        cube->map->player->offset = -max_offset;
    else
        cube->map->player->offset -= increment;
}

void rotate_down(t_cube *cube)
{
    double increment = MINI_SCALE / FINE_RATIO * X_RATIO;
    double max_offset = Y_RES / 2 - MINI_SCALE;
    if (cube->map->player->offset + increment >= max_offset)
        cube->map->player->offset = max_offset;
    else
        cube->map->player->offset += increment;
}




void move_front(t_cube *cube)
{
    int next_x;
    int next_y;
    float angle_rad;
    float sin_angle;
    float cos_angle;

    angle_rad = (cube->map->player->p_pos_a - 90) * M_PI / 180.0;
    sin_angle = sin(angle_rad);
    cos_angle = cos(angle_rad);
    next_x = cube->map->player->p_pos_x + (MINI_SCALE / FINE_RATIO) * cos_angle;
    next_y = cube->map->player->p_pos_y + (MINI_SCALE / FINE_RATIO) * sin_angle;
    if (cube->map->m_wall[next_y][next_x] == 1)
        return;
    cube->map->player->p_pos_x += (MINI_SCALE / FINE_RATIO) * cos_angle;
    cube->map->player->p_pos_y += (MINI_SCALE / FINE_RATIO) * sin_angle;
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
	if (cube->map->m_wall[next_y][next_x] == 1)
		return ;
	cube->map->player->p_pos_x += (MINI_SCALE / FINE_RATIO) * cos_angle;
	cube->map->player->p_pos_y += (MINI_SCALE / FINE_RATIO) * sin_angle;
}

void	move_up(t_cube *cube)
{
	cube->map->player->p_pos_y -= MINI_SCALE / FINE_RATIO;
}

void	move_left(t_cube *cube)
{
	cube->map->player->p_pos_x -= MINI_SCALE / FINE_RATIO;
}

void	move_down(t_cube *cube)
{
	cube->map->player->p_pos_y += MINI_SCALE / FINE_RATIO;
}

void	move_right(t_cube *cube)
{
	cube->map->player->p_pos_x += MINI_SCALE / FINE_RATIO;
}
