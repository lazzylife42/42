/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:35:21 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/19 21:58:26 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_wall(t_cube *cube, t_raycast *ray)
{
	double	camera_height;

	camera_height = cube->map->player->offset;
	set_wall_parameters(ray, cube, camera_height);
	cube->ray = ray;
	draw_textures(cube, (t_vec){ray->col, ray->wall_top}, (t_vec){ray->col,
		ray->wall_bottom}, 0);
}

void	draw_wall(t_cube *cube)
{
	t_raycast	ray;

	ray.col = 0;
	while (ray.col < X_RES)
	{
		ray = initialize_raycast(cube, ray.col);
		ray.hit = 0;
		perform_dda(cube, &ray);
		render_wall(cube, &ray);
		ray.col++;
	}
}
