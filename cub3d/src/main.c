/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:28:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/14 18:14:10 by smonte-e         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
	{
		ft_putstr_fd(RED "Bad Args :\n" GRN "Try : <" BLU "./cube" GRN "> <" BLU "map/\'your_chosen _map\'" GRN ">\n" RST,
			2);
		exit(EXIT_FAILURE);
	}
	cube.mlx_ptr = mlx_init();
	if (!cube.mlx_ptr)
		return (1);
	map_renderer_init(&cube, argv);
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
