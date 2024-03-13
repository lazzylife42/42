/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:52:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/12 21:13:04 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void mlx_pixel(t_img *img, t_vec pos, int color)
{
    char *dst;

    if (pos.x < 0 || pos.x >= X_RES || pos.y < 0 || pos.y >= Y_RES)
        return;
    dst = img->addr + (pos.y * img->line_length + pos.x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}


void draw_line(t_img *img, t_vec start, t_vec end, int color)
{
	int dx = abs(end.x - start.x);
	int dy = abs(end.y - start.y);
	int sx = (start.x < end.x) ? 1 : -1;
	int sy = (start.y < end.y) ? 1 : -1;
	int err = dx - dy;
	int e2;
	int max_iter = dx + dy;

	if (start.x < 0 || start.x >= X_RES || start.y < 0 || start.y >= Y_RES ||
		end.x < 0 || end.x >= X_RES || end.y < 0 || end.y >= Y_RES)
		return;
	if (start.x == end.x && start.y == end.y)
		return;

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
			break;
	}
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

void draw_rec(t_img *img, t_vec start, t_vec end, int color)
{
    int j = start.y;
    while (j <= end.y)
    {
        int i = start.x;
        while (i <= end.x)
        {
            mlx_pixel(img, (t_vec){i, j}, color);
            i++;
        }
        j++;
    }
}

float distance(t_vec p1, t_vec p2)
{
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}

void draw_triangle(t_cube *cube)
{
	float angle_rad = (cube->map->player->p_pos_a) * M_PI / 180;
	float cos_angle = cos(angle_rad);
	float sin_angle = sin(angle_rad);

	t_vec top = {cube->map->player->p_pos_x, cube->map->player->p_pos_y - MINI_SCALE / 2};
	t_vec bottom_left = {cube->map->player->p_pos_x - MINI_SCALE / 2, cube->map->player->p_pos_y + MINI_SCALE / 2};
	t_vec bottom_right = {cube->map->player->p_pos_x + MINI_SCALE / 2, cube->map->player->p_pos_y + MINI_SCALE / 2};
	t_vec rotated_top = {
		cube->map->player->p_pos_x + (top.x - cube->map->player->p_pos_x) * cos_angle - (top.y -  cube->map->player->p_pos_y) * sin_angle,
		 cube->map->player->p_pos_y + (top.x - cube->map->player->p_pos_x) * sin_angle + (top.y -  cube->map->player->p_pos_y) * cos_angle
	};
	t_vec rotated_bottom_left = {
		cube->map->player->p_pos_x + (bottom_left.x - cube->map->player->p_pos_x) * cos_angle - (bottom_left.y -  cube->map->player->p_pos_y) * sin_angle,
		 cube->map->player->p_pos_y + (bottom_left.x - cube->map->player->p_pos_x) * sin_angle + (bottom_left.y -  cube->map->player->p_pos_y) * cos_angle
	};
	t_vec rotated_bottom_right = {
		cube->map->player->p_pos_x + (bottom_right.x - cube->map->player->p_pos_x) * cos_angle - (bottom_right.y -  cube->map->player->p_pos_y) * sin_angle,
		 cube->map->player->p_pos_y + (bottom_right.x - cube->map->player->p_pos_x) * sin_angle + (bottom_right.y -  cube->map->player->p_pos_y) * cos_angle
	};
	draw_line(cube->img, rotated_top, rotated_bottom_left, 0xFF0000);
	draw_line(cube->img, rotated_top, rotated_bottom_right, 0xFF0000);
	draw_line(cube->img, rotated_bottom_left, rotated_bottom_right, 0xFF0000);
}
