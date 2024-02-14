/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:28:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/14 10:53:53 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	on_destroy(t_cube *data)
{
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
	{
		ft_putstr_fd(RED "Bad Args :\n" GRN "Try : <" BLU "./cube" GRN "> <"
		BLU "map/\'your_chosen _map\'" GRN ">\n" RST, 2);
		exit(EXIT_FAILURE);
	}
	cube.mlx_ptr = mlx_init();
	if (!cube.mlx_ptr)
		return (1);
	map_renderer_init(&cube, argv);
	cube.img = (t_img *)malloc(sizeof(t_img));
	if (!cube.img)
		return(1);
	cube.win_ptr = mlx_new_window(cube.mlx_ptr, X_RES, Y_RES, "Cub3d");
	cube.img->img = mlx_new_image(cube.mlx_ptr, X_RES, Y_RES);
	cube.img->addr = mlx_get_data_addr(cube.img->img, &cube.img->bits_per_pixel,
			&cube.img->line_length, &cube.img->endian);
	map_renderer(&cube);
	// draw_square(cube.img, (t_vec){540, 0}, 64, 0xFFFFFF);
	mlx_put_image_to_window(cube.mlx_ptr, cube.win_ptr, cube.img->img, 0, 0);
	mlx_hook(cube.win_ptr, 3, 0, &player_move, &cube);
	mlx_hook(cube.win_ptr, 17, 0, &on_destroy, &cube);
	mlx_loop(cube.mlx_ptr);

	return (0);
}
