/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:07:56 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/11 16:37:57 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	calculate_movement(t_cube *cube, t_vec mouse_pos, t_vec center)
{
	float	max_offset;
	float	dx;
	float	dy;
	float	t_angle;
	float	t_offset;

	mlx_mouse_get_pos(cube->win_ptr, &mouse_pos.x, &mouse_pos.y);
	max_offset = (float)(Y_RES / 2 - MINI_SCALE);
	if (mouse_pos.x != center.x || mouse_pos.y != center.y)
	{
		dx = ((float)mouse_pos.x - center.x) * M_SENSITIVITY;
		dy = ((float)mouse_pos.y - center.y) * M_SENSITIVITY;
		t_angle = cube->map->player->p_pos_a + dx;
		cube->map->player->p_pos_a += (t_angle - cube->map->player->p_pos_a)
			* M_SENSITIVITY;
		t_offset = cube->map->player->offset + dy * MINI_SCALE / FINE_RATIO
			* X_RATIO;
		cube->map->player->offset += (t_offset - cube->map->player->offset)
			* M_SENSITIVITY;
		if (cube->map->player->offset < -max_offset)
			cube->map->player->offset = -max_offset;
		else if (cube->map->player->offset > max_offset)
			cube->map->player->offset = max_offset;
		mlx_mouse_move(cube->win_ptr, (int)center.x, (int)center.y);
	}
}

void	handle_mouse(t_cube *cube)
{
	t_vec	mouse_pos;
	t_vec	center;

	mouse_pos.x = 0;
	mouse_pos.y = 0;
	center = (t_vec){(float)X_RES / 2, (float)Y_RES / 2};
	calculate_movement(cube, mouse_pos, center);
}
