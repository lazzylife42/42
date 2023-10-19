/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:58:19 by sab               #+#    #+#             */
/*   Updated: 2023/10/19 16:08:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int map[5][5] = {
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1,
};

int main(void)
{
	t_mlx_data	data;
	
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, 400, 300, "window");
	if (data.mlx_win == NULL)
	{
		mlx_destroy_window(data.mlx, data.mlx_win);
		free(data.mlx);
		return (1);
	}
	sprite_init(data, 400, 300, new_pixel_data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	
//	mlx_key_hook(data.mlx_win, handle_imput, &data);
	mlx_loop(data.mlx_win);
    mlx_destroy_window(data.mlx, data.mlx_win);
	return (0);
}


/*
typedef struct  s_data
{
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	int         width;   // Ajoutez ces membres
	int         height;  // Ajoutez ces membres
}               t_data;

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 232, 300, "Coucou!");

	// Chargez votre image XPM
	img.img = mlx_xpm_file_to_image(mlx, "img.xpm", &img.width, &img.height);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/
