/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:52:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/14 12:20:42 by smonte-e         ###   ########.fr       */
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

void draw_triangle(t_img *img, t_vec center, int size, float angle)
{
    float angle_rad = angle * M_PI / 180.0;
    float cos_angle = cos(angle_rad);
    float sin_angle = sin(angle_rad);

    // Coordonnées des sommets du triangle non-roté
    t_vec top = {center.x, center.y - size / 2};
    t_vec bottom_left = {center.x - size / 2, center.y + size / 2};
    t_vec bottom_right = {center.x + size / 2, center.y + size / 2};

    // Coordonnées des sommets du triangle roté
    t_vec rotated_top = {
        center.x + (top.x - center.x) * cos_angle - (top.y - center.y) * sin_angle,
        center.y + (top.x - center.x) * sin_angle + (top.y - center.y) * cos_angle
    };
    t_vec rotated_bottom_left = {
        center.x + (bottom_left.x - center.x) * cos_angle - (bottom_left.y - center.y) * sin_angle,
        center.y + (bottom_left.x - center.x) * sin_angle + (bottom_left.y - center.y) * cos_angle
    };
    t_vec rotated_bottom_right = {
        center.x + (bottom_right.x - center.x) * cos_angle - (bottom_right.y - center.y) * sin_angle,
        center.y + (bottom_right.x - center.x) * sin_angle + (bottom_right.y - center.y) * cos_angle
    };

    // Dessiner les côtés du triangle
    draw_line(img, rotated_top, rotated_bottom_left, 0xFF0000);
    draw_line(img, rotated_top, rotated_bottom_right, 0xFF0000);
    draw_line(img, rotated_bottom_left, rotated_bottom_right, 0xFF0000);
	draw_line(img, center, rotated_top, 0x00FF00);
}

