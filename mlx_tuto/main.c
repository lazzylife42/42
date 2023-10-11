/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:58:19 by sab               #+#    #+#             */
/*   Updated: 2023/10/11 19:16:45 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/minilibx-linux/mlx.h"
#include "lib/libft/libft.h"
#include <time.h>


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img = "morsay.jpg";
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 232, 300, "Truand De La Galère!");
	mlx_new_image(img, 232, 300);
		wait(10000);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	

	mlx_loop(mlx);
}