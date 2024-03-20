/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:52:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/17 18:54:42 by smonte-e         ###   ########.fr       */
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

t_draw	draw_line_init(t_vec start, t_vec end)
{
	t_draw	draw;

	draw.dx = abs(end.x - start.x);
	draw.dy = abs(end.y - start.y);
	if (start.x < end.x)
		draw.sx = 1;
	else
		draw.sx = -1;
	if (start.y < end.y)
		draw.sy = 1;
	else
		draw.sy = -1;
	draw.err = draw.dx - draw.dy;
	draw.max_iter = draw.dx + draw.dy;
	return (draw);
}

void	draw_line(t_img *img, t_vec start, t_vec end, int color)
{
	t_draw	draw;

	draw = draw_line_init(start, end);
	if (start.x < 0 || start.x >= X_RES || start.y < 0 || start.y >= Y_RES
		|| end.x < 0 || end.x >= X_RES || end.y < 0 || end.y >= Y_RES
		|| (start.x == end.x && start.y == end.y))
		return ;
	while (draw.max_iter--)
	{
		if (start.x >= 0 && start.x < X_RES && start.y >= 0 && start.y < Y_RES)
			mlx_pixel(img, (t_vec){start.x, start.y}, color);
		draw.e2 = 2 * draw.err;
		if (draw.e2 > -draw.dy)
		{
			draw.err -= draw.dy;
			start.x += draw.sx;
		}
		if (draw.e2 < draw.dx)
		{
			draw.err += draw.dx;
			start.y += draw.sy;
		}
		if (start.x == end.x && start.y == end.y)
			break ;
	}
}
