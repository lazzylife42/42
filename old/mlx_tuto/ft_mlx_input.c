/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:55:52 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/19 12:21:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "ft_mlx.h"

int handle_imput(int keysym, t_mlx_data *data)
{
	if (keysym == 53)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (1);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}