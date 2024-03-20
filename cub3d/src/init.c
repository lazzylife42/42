/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:26:33 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/19 22:05:08 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_mlx(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	if (!cube->mlx_ptr)
		return (0);
	return (1);
}

int	init_map(t_cube *cube)
{
	cube->map = malloc(sizeof(t_map));
	if (cube->map == NULL)
		ft_error(RED "Error\nMalloc failed\n" RST);
	cube->map->textures = malloc(sizeof(t_textures));
	if (cube->map->textures == NULL)
		ft_error(RED "Error\nMalloc failed\n" RST);
	return (1);
}

int	init_ray_and_img(t_cube *cube)
{
	cube->ray = NULL;
	cube->img = (t_img *)malloc(sizeof(t_img));
	if (!cube->img)
		return (0);
	return (1);
}

int	init_window(t_cube *cube)
{
	cube->win_ptr = mlx_new_window(cube->mlx_ptr, X_RES, Y_RES, "Cub3d");
	if (!cube->win_ptr)
		return (0);
	return (1);
}

int	init_load_and_textures(t_cube *cube)
{
	cube->loadscreen = false;
	cube->load = malloc(sizeof(t_load));
	if (!cube->load)
		return (0);
	load_melt_textures(cube);
	if (!init_textures(cube, cube->map->textures))
		return (0);
	return (1);
}
