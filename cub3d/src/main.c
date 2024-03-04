/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:28:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/04 20:22:34 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_destroy(t_cube *cube)
{
	free_map(cube);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	init_all(t_cube *cube, char **argv)
{
	cube->mlx_ptr = mlx_init();
	if (!cube->mlx_ptr)
		return (0);
	map_renderer_init(cube, argv);
	init_player(cube);
	key_init(cube);
	cube->ray = (t_raycast *)malloc(sizeof(t_raycast));
	if (!cube->ray)
		return (0);
	cube->img = (t_img *)malloc(sizeof(t_img));
	if (!cube->img)
		return (0);
	cube->win_ptr = mlx_new_window(cube->mlx_ptr, X_RES, Y_RES, "Cub3d");
	cube->loadscreen = false;
	cube->load = malloc(sizeof(t_load));
	load_melt_textures(cube);
	if (!init_textures(cube))
		return (0);
	return (1);
}

int	game_loop(t_cube *cube)
{
	if (cube->loadscreen == false)
	{
		loadscreen(cube);
		update_player(cube);
	}
	else
	{
		cube->img->img = mlx_new_image(cube->mlx_ptr, X_RES, Y_RES);
		cube->img->addr = mlx_get_data_addr(cube->img->img,
				&cube->img->bits_per_pixel, &cube->img->line_length,
				&cube->img->endian); 
		mlx_mouse_hide();
		handle_mouse(cube);
		update_player(cube);
		map_renderer(cube);
		mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0,
			0);
		// mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->text->t_img[0].img, 0,
		// 	0);
		// mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->text->t_img[1].img, 300,
		// 	0);
		// mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->text->t_img[2].img, 0,
		// 	300);
		// mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->text->t_img[3].img, 300,
		// 	300);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
	{
		ft_putstr_fd(RED "Bad Args :\n" GRN "Try : <" BLU "./cube" GRN
			"> <" BLU "map/\'your_chosen _map\'" GRN ">\n" RST,
			2);
		exit(EXIT_FAILURE);
	}
	if (!init_all(&cube, argv))
		return (1);
	mlx_loop_hook(cube.mlx_ptr, game_loop, &cube);
	mlx_hook(cube.win_ptr, 2, 1L << 0, &keypress, &cube);
	mlx_hook(cube.win_ptr, 3, 1L << 1, &keyrelease, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}
