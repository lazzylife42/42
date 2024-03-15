/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:52:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/15 21:12:59 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlx_pixel(t_img *img, t_vec pos, int color)
{
	char	*dst;

	if (pos.x < 0 || pos.x >= X_RES || pos.y < 0 || pos.y >= Y_RES)
		return ;
	dst = img->addr + (pos.y * img->line_length + pos.x * (img->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_img *img, t_vec pos, int size, int color)
{
	int	i;
	int	j;

	i = pos.x;
	j = pos.y;
	while (i <= pos.x + size)
	{
		j = pos.y;
		while (j <= pos.y + size)
		{
			mlx_pixel(img, (t_vec){i, j}, color);
			j++;
		}
		i++;
	}
}

void	draw_rec(t_img *img, t_vec start, t_vec end, int color)
{
	int	j;
	int	i;

	j = start.y;
	while (j <= end.y)
	{
		i = start.x;
		while (i <= end.x)
		{
			mlx_pixel(img, (t_vec){i, j}, color);
			i++;
		}
		j++;
	}
}

void	draw_line(t_img *img, t_vec start, t_vec end, int color)
{
	int dx = abs(end.x - start.x);
	int dy = abs(end.y - start.y);
	int sx = (start.x < end.x) ? 1 : -1;
	int sy = (start.y < end.y) ? 1 : -1;
	int err = dx - dy;
	int e2;
	int max_iter = dx + dy;

	if (start.x < 0 || start.x >= X_RES || start.y < 0 || start.y >= Y_RES
			|| end.x < 0 || end.x >= X_RES || end.y < 0 || end.y >= Y_RES)
		return ;
	if (start.x == end.x && start.y == end.y)
		return ;
	while (max_iter--)
	{
		if (start.x >= 0 && start.x < X_RES && start.y >= 0 && start.y < Y_RES)
		{
			mlx_pixel(img, (t_vec){start.x, start.y}, color);
		}
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			start.y += sy;
		}
		if (start.x == end.x && start.y == end.y)
			break ;
	}
}

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
