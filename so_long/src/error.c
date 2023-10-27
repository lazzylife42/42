/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:57:33 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:08 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
# define "La carte doit être de forme rectangulaire." 10
# define "La carte doit être fermée en étant encadrée par des murs." 11
# define "La carte doit avoir un chemin valide." 12
# define "La carte ne peut etre vide." 13
*/

void	error_init(t_error *error)
{
	error->empty = FALSE;
	error->square = FALSE;
	error->walls = FALSE;
	error->v_path = FALSE;
	error->bad_char = FALSE;
	error->bad_map = FALSE;
}

void	error_size(t_error *error, t_data *data)
{
	int x;
	int y;
	int cells;

	cells = data->map_width;
	if (data->map_width == 0 || data->map_height == 0)
		error->empty = TRUE;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			error_char(error, data->map[y][x]);
			if (y == 0 || y == data->map_height)
			{
				if (data->map[y][x] != '1')
					error->walls = TRUE;
			}
			else if (y > 0 && y < data->map_height)
			{
				if (data->map[y][0] != '1' || data->map[y][data->map_width - 1] != '1')
					error->walls = TRUE;
			}
			x++;
		}
		y++;
	}
}

void	error_char(t_error *error, char c)
{
	char *allow = "01PCEB";
	int	flag;
	int i;

	flag = 0;
	i = 0;
	while (*allow)
	{
		if (c == allow[i])
			flag = 1;
		allow++;	
	}
	if (flag == 0)
		error->bad_char = TRUE;
}

void	error_elements(t_error *error, t_data *data)
{
	int x;
	int y;
	int p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
				p = 1;
			else if (data->map[y][x] == 'E')
				e = 1;
			else if (data->map[y][x] == 'C')
				c = 1;
			x++;
		}
		y++;
	}
	if (p == 0 || e == 0 || c == 0)
		error->bad_map = TRUE;
}

void	error_square(t_error *error, t_data *data)
{
    int expected_width;
    int y;

	expected_width = data->map_width;
	y = 0;
    while (y < data->map_height)
    {
        if (data->map[y] == NULL || (int)ft_strlen(data->map[y]) != expected_width)
        {
            error->square = TRUE;
        }
		y++;
    }
}

void	error_check(t_error *error, t_data *data)
{
	int flag = FALSE;
	error_init(error);
	error_square(error, data);
	error_elements(error, data);
	error_size(error, data);
	error_path(error, data);
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
	ft_printf("\n[%d][%d][%d][%d][%d][%d]\n\n",	error->empty, 
												error->square,
												error->walls,
												error->v_path,
												error->bad_char,
												error->bad_map);
//	if (flag == TRUE)
//		off_destroy(data);
											
}