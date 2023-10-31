/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:53:58 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/31 22:53:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_empty(t_error *error, t_data *data)
{
	if (data->map_width == 0 || data->map_height == 0
		|| data->map_width == 1 || data->map_height == 1)
		error->empty = TRUE;
}

void	error_check(t_error *error, t_data *data)
{
	t_data	*cp;

	error_init(error);
	error_empty(error, data);
	if (error->empty)
		write(2, "Error\nLa carte ne peut etre vide.\n", 34);
	error_square(error, data);
	if (error->square)
		write(2, "Error\nLa carte doit être de forme rectangulaire.\n", 50);
	error_size(error, data);
	if (error->walls)
		write(2, "Error\nLa carte doit être encadrée par des murs.\n", 50);
	if (error->overflow)
		write(2, "Error\nLes dimentions des la carte sont trop grandes.\n", 53);
	cp = copy_data(data);
	error_path(error, cp);
	if (error->v_path)
		write(2, "Error\nIl néxiste pas de chemin valide.\n", 40);
	free_map(cp);
	error_elements(error, data);
	if (error->bad_char)
		write(2, "Error\nLa carte est corrompue.\n", 30);
	if (error->bad_map)
		write(2, "Error\nLa carte ne dispose pas des éléments minimums.\n", 54);
	error_exit(error, data);
}

void	error_exit(t_error *error, t_data *data)
{
	if (error->empty || error->square || error->walls
		|| error->overflow || error->v_path || error->bad_char
		|| error->bad_map)
	{
		ft_printf("\n\n[%d][%d][%d][%d][%d][%d][%d]\n",
			error->empty, error->square, error->walls,
			error->overflow, error->v_path, error->bad_char,
			error->bad_map);
		off_destroy(data);
	}
}
