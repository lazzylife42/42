/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:28:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 19:17:27 by smonte-e         ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	// t_cube data;
	if (argc != 2)
	{
		ft_putstr_fd(RED "Bad Args :\n" GRN "Try : <" BLU "./cube" GRN "> <"
			BLU "map/\'your_chosen _map\'" GRN ">\n" RST, 2);
		exit(EXIT_FAILURE);
	}
	// data.mlx_ptr = mlx_init();
	// if (!data.mlx_ptr)
	//     return (1);
	// map_renderer_init(&data, argv);
	// map_renderer(&data);
	(void)argv;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, X_RES, Y_RES, "Hello world!");
	img.img = mlx_new_image(mlx, X_RES, Y_RES);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_pixel(&img, (t_vec){0, 540}, 0xFFFFFF);
	draw_square(img, (t_vec){50, 50}, 64, 0xFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	// mlx_hook(data.win_ptr, 3, 0, &player_move, &data);
	// mlx_hook(data.win_ptr, 17, 0, &on_destroy, &data);
	// mlx_loop(data.mlx_ptr);
	return (0);
}
