/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/25 11:32:22 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
 
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
	map_renderer_init(&data, argv);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map_width) * 64, (data.map_height) * 64, "Les Singes Viennent de Sortir du Zoo");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	data.moves = 0;

	map_renderer(&data);
	mlx_hook(data.win_ptr, 3, 0, &player_move, &data);
	mlx_hook(data.win_ptr, 17, 0, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}