/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:52:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/20 10:26:08 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_pixel(t_img *img, t_vec pos, int color)
{
	char	*dst;

	dst = img->addr + (pos.y * img->line_length + pos.x * (img->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_img *img, t_vec start, t_vec end, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	sx = start.x < end.x ? 1 : -1;
	sy = start.y < end.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel(img, (t_vec){start.x, start.y}, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			start.y += sy;
		}
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

float distance(t_vec p1, t_vec p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

void draw_triangle(t_cube *cube)
{
    // Calcul de l'angle de vue en radians
    float angle_rad = (cube->map->player->p_pos_a) * M_PI / 180;
    float cos_angle = cos(angle_rad);
    float sin_angle = sin(angle_rad);

    // Coordonnées des sommets du triangle non-roté
    t_vec top = {cube->map->player->p_pos_x, cube->map->player->p_pos_y - MINI_SCALE / 2};
    t_vec bottom_left = {cube->map->player->p_pos_x - MINI_SCALE / 2, cube->map->player->p_pos_y + MINI_SCALE / 2};
    t_vec bottom_right = {cube->map->player->p_pos_x + MINI_SCALE / 2, cube->map->player->p_pos_y + MINI_SCALE / 2};

    // Coordonnées des sommets du triangle roté
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

    // Dessiner les côtés du triangle
    draw_line(cube->img, rotated_top, rotated_bottom_left, 0xFF0000);
    draw_line(cube->img, rotated_top, rotated_bottom_right, 0xFF0000);
    draw_line(cube->img, rotated_bottom_left, rotated_bottom_right, 0xFF0000);

    // Dessiner le rayon de vision
    // draw_line(cube->img, (t_vec){cube->map->player->p_pos_x, cube->map->player->p_pos_y}, raycast(cube), 0x008000);
}

