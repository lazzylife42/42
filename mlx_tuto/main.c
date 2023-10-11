/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:58:19 by sab               #+#    #+#             */
/*   Updated: 2023/10/11 22:57:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/minilibx/mlx.h"
#include "lib/libft/libft.h"
#include <time.h>


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img = "morsay.jpg";

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 232, 300, "Coucou!");
	

	mlx_loop(mlx);
}