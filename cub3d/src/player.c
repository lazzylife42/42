/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:59:05 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/12 22:36:49 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	rotate_up(t_cube *cube)
{
	double	increment;
	double	max_offset;

	increment = MINI_SCALE / FINE_RATIO * X_RATIO;
	max_offset = Y_RES / 2 - MINI_SCALE;
	if (cube->map->player->offset - increment <= -max_offset)
		cube->map->player->offset = -max_offset;
	else
		cube->map->player->offset -= increment;
}

void	rotate_down(t_cube *cube)
{
	double	increment;
	double	max_offset;

	increment = MINI_SCALE / FINE_RATIO * X_RATIO;
	max_offset = Y_RES / 2 - MINI_SCALE;
	if (cube->map->player->offset + increment >= max_offset)
		cube->map->player->offset = max_offset;
	else
		cube->map->player->offset += increment;
}
