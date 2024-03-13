/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:28:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/09 16:34:03 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	cube.mlx_ptr = mlx_init();
	if (!cube.mlx_ptr)
		return (1);
	cube.map = malloc(sizeof(t_map));
	if (cube.map == NULL)
		ft_error(RED "Error\nMalloc failed\n" RST);
	if (check_args(argc) == 0 && check_map_file(argv[1]) == 0
		&& check_textures(argv[1]) == 0)
		set_map(argv[1], argv, &cube);
	init_player(&cube);
	cube.img = (t_img *)malloc(sizeof(t_img));
	if (!cube.img)
		return (1);
	cube.win_ptr = mlx_new_window(cube.mlx_ptr, X_RES, Y_RES, "Cub3d");
	frame_render(&cube);
	mlx_hook(cube.win_ptr, 3, 0, &player_move, &cube);
	mlx_hook(cube.win_ptr, 17, 0, &on_destroy, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}
