/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:28:24 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/13 17:11:31 by smonte-e         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_cube data;
    
    if (argc != 2)
    {
        ft_putstr_fd(RED"Bad Args :\n"GRN"Try : <"BLU"./cube"GRN"> <"BLU"map/\'your_chosen _map\'"GRN">\n"RST, 2);
        exit(EXIT_FAILURE);
    }
    data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
    map_renderer_init(&data, argv);
    data.win_ptr = mlx_new_window(data.mlx_ptr, X_RES, Y_RES, "Cub3d");
    map_renderer(&data);
	mlx_hook(data.win_ptr, 3, 0, &player_move, &data);
	mlx_hook(data.win_ptr, 17, 0, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
    printf(GRN"coucou\n"RST);
    return 0;
    
}
