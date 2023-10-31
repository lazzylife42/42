/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:53:58 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/31 17:18:07 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_empty(t_error *error, t_data *data)
{
	if (data->map_width == 0 || data->map_height == 0)
		error->empty = TRUE;
}

void	error_check(t_error *error, t_data *data)
{
	int		flag;
	t_data	*cp;

	flag = FALSE;
	cp = copy_data(data);
	error_empty(error, data);
	error_init(error);
	error_square(error, data);
	error_elements(error, data);
	error_size(error, data);
	error_path(error, cp);
	free_data(cp);
	if (error->empty)
	{
		ft_printf("La carte ne peut etre vide.\n");
		flag = TRUE;
	}
	if (error->square)
	{
		ft_printf("La carte doit être de forme rectangulaire.\n");
		flag = TRUE;
	}
	if (error->walls)
	{
		ft_printf("La carte doit être fermée en étant encadrée par des murs.\n");
		flag = TRUE;
	}
	if (error->overflow)
	{
		ft_printf("Les dimentions des la carte sont trop grandes.\n");
		flag = TRUE;
	}
	if (error->v_path)
	{
		ft_printf("Il néxiste pas de chemin valide.\n");
		flag = TRUE;
	}
	if (error->bad_char)
	{
		ft_printf("La carte est corrompue.\n");
		flag = TRUE;
	}
	if (error->bad_map)
	{
		ft_printf("La carte ne dispoe pas des éléments minimums.\n");
		flag = TRUE;
	}
	if (flag == TRUE)
		off_destroy(data);
}
