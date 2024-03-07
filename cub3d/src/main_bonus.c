/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:16:13 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/01 17:12:58 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
	return (1);
}

int	game_loop(t_cube *cube)
{
	fps_count();
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