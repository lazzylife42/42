/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:16:13 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/19 22:06:23 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <time.h>

static int		g_frame_count = 0;
static time_t	g_start_time = 0;

void	fps_count(void)
{
	time_t	current_time;
	double	elapsed_time;
	double	fps;

	if (g_start_time == 0)
		g_start_time = time(NULL);
	g_frame_count++;
	current_time = time(NULL);
	elapsed_time = difftime(current_time, g_start_time);
	if (elapsed_time >= 1)
	{
		fps = g_frame_count / elapsed_time;
		printf("FPS: %.2f\n", fps);
		g_frame_count = 0;
		g_start_time = current_time;
	}
}

int	on_destroy(t_cube *cube)
{
	free_textures(cube->map->textures);
	free_map(cube);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
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
		mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr,
			cube->text->t_img[5].img, 0, Y_RES - HUD);
	}
	return (0);
}

int	init_all(t_cube *cube, char **argv, int argc)
{
	if (!init_mlx(cube) || !init_map(cube))
		return (0);
	if (check_args(argc) == 0 && check_map_file(argv[1]) == 0
		&& check_textures(argv[1], cube, cube->map->textures) == 0)
		set_map(argv[1], argv, cube);
	init_player(cube);
	key_init(cube);
	if (!init_ray_and_img(cube) || !init_window(cube)
		|| !init_load_and_textures(cube))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (!init_all(&cube, argv, argc))
		return (1);
	mlx_loop_hook(cube.mlx_ptr, game_loop, &cube);
	mlx_hook(cube.win_ptr, 2, 1L << 0, &keypress, &cube);
	mlx_hook(cube.win_ptr, 3, 1L << 1, &keyrelease, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}
