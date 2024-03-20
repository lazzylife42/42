/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:53:37 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/17 18:54:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_vecf	rotate_point(t_vecf pos, float cx, float cy, float angle_rad)
{
	t_vecf	rotated_point;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(angle_rad);
	sin_angle = sin(angle_rad);
	rotated_point.x = cx + (pos.x - cx) * cos_angle - (pos.y - cy) * sin_angle;
	rotated_point.y = cy + (pos.x - cx) * sin_angle + (pos.y - cy) * cos_angle;
	return (rotated_point);
}

static void	draw_rotated_triangle_lines(t_cube *cube, t_vecf rotated_top,
		t_vecf rotated_bottom_left, t_vecf rotated_bottom_right)
{
	draw_line(cube->img, (t_vec){(int)rotated_top.x, (int)rotated_top.y},
		(t_vec){(int)rotated_bottom_left.x, (int)rotated_bottom_left.y},
		0xFF0000);
	draw_line(cube->img, (t_vec){(int)rotated_top.x, (int)rotated_top.y},
		(t_vec){(int)rotated_bottom_right.x, (int)rotated_bottom_right.y},
		0xFF0000);
	draw_line(cube->img, (t_vec){(int)rotated_bottom_left.x,
		(int)rotated_bottom_left.y}, (t_vec){(int)rotated_bottom_right.x,
		(int)rotated_bottom_right.y}, 0xFF0000);
}

void	draw_triangle(t_cube *cube)
{
	float	angle_rad;
	t_tri	triangle;

	angle_rad = (cube->map->player->p_pos_a) * M_PI / 180;
	triangle = (t_tri){.top = {cube->map->player->p_pos_x,
		cube->map->player->p_pos_y - MINI_SCALE / 2},
		.bottom_left = {cube->map->player->p_pos_x - MINI_SCALE / 2,
		cube->map->player->p_pos_y + MINI_SCALE / 2},
		.bottom_right = {cube->map->player->p_pos_x + MINI_SCALE / 2,
		cube->map->player->p_pos_y + MINI_SCALE / 2}};
	draw_rotated_triangle_lines(cube, rotate_point(triangle.top,
			cube->map->player->p_pos_x, cube->map->player->p_pos_y, angle_rad),
		rotate_point(triangle.bottom_left, cube->map->player->p_pos_x,
			cube->map->player->p_pos_y, angle_rad),
		rotate_point(triangle.bottom_right, cube->map->player->p_pos_x,
			cube->map->player->p_pos_y, angle_rad));
}
