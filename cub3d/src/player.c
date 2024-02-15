/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:59:05 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/15 14:09:10 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_move(int keysym, t_cube *cube)
{
	if (keysym == 53)
		on_destroy(cube);
	else if (keysym == 123)
		rotate_left(cube);
	else if (keysym == 124)
		rotate_right(cube);
	else if (keysym == 13)
		move_up(cube);
	else if (keysym == 126)
		move_front(cube);
	else if (keysym == 125)
		move_back(cube);
	else if (keysym == 0)
		move_left(cube);
	else if (keysym == 1)
		move_down(cube);
	else if (keysym == 2)
		move_right(cube);
	// printf("Key : %d\n", keysym);
	frame_render(cube);
	return (0);
}

void	rotate_left(t_cube *cube)
{
	cube->map->player->p_pos_a -= 90 / FINE_RATIO;
}

void	rotate_right(t_cube *cube)
{
	cube->map->player->p_pos_a += 90 / FINE_RATIO;
}

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
	next_x = (MINI_SCALE / FINE_RATIO) * cos_angle + cube->map->player->p_pos_x;
	next_y = (MINI_SCALE / FINE_RATIO) * cos_angle + cube->map->player->p_pos_y;
	if (cube->map->m_wall[next_y][next_x] == 1)
		return ;
	cube->map->player->p_pos_x += (MINI_SCALE / FINE_RATIO) * cos_angle;
	cube->map->player->p_pos_y += (MINI_SCALE / FINE_RATIO) * sin_angle;
}

void	move_back(t_cube *cube)
{
	int		next_x;
	int		next_y;
	float angle_rad;
	float sin_angle;
	float cos_angle;

	angle_rad = (cube->map->player->p_pos_a + 90) * M_PI / 180.0;
	sin_angle = sin(angle_rad);
	cos_angle = cos(angle_rad);
	next_x = (MINI_SCALE / FINE_RATIO) * cos_angle + cube->map->player->p_pos_x;
	next_y = (MINI_SCALE / FINE_RATIO) * cos_angle + cube->map->player->p_pos_y;
	if (cube->map->m_wall[next_y][next_x] == 1)
		return ;
	cube->map->player->p_pos_x += (MINI_SCALE / FINE_RATIO) * cos_angle ;
	cube->map->player->p_pos_y += (MINI_SCALE / FINE_RATIO) * sin_angle ;

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
