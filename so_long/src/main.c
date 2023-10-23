/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/23 15:37:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == 53)
		on_destroy(data);
	ft_printf("Pressed key: %d\n\n", keysym);
	return (0);
}
 
int main(int argc, char **argv)
{
	t_data 	data;
	if (argc != 2)
	{
		write(STDERR_FILENO, "Error\nBad ARG\n", 14);
		exit(EXIT_FAILURE);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 896, 448, "Les Singes Viennent de Sortir du Zoo");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

/*
	data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/kaaris.xpm", &data.width, &data.height);
	data.textures[1] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/harambe.xpm", &data.width, &data.height);
    data.textures[2] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile01.xpm", &data.width, &data.height);
    data.textures[3] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile02.xpm", &data.width, &data.height);
    data.textures[4] = mlx_xpm_file_to_image(data.mlx_ptr, "sprites/xpm/tile03.xpm", &data.width, &data.height);
*/	map_to_str(&data, &argv[1]);
	
/*	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], 64, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[2], 128, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[3], 192, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[4], 256, 0);
*/	
	mlx_hook(data.win_ptr, 3, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}