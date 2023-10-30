/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:57:33 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/30 22:55:42 by smonte-e         ###   ########.fr       */
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
	error->overflow = FALSE;
	error->v_path = FALSE;
	error->bad_char = FALSE;
	error->bad_map = FALSE;
}

void	error_size(t_error *error, t_data *data)
{
	int x;
	int y;

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

void error_square(t_error *error, t_data *data)
{
    int y;
    int expected_width = -1;  // Initialise à -1 pour la première ligne

    y = 0;
    if (data->map_width >= 28 || data->map_height >= 22)
        error->overflow = TRUE;
    while (y < data->map_height)
    {
        if (data->map[y] == NULL)
		{
            error->square = TRUE;
            ft_printf("ERROR: NULL line at [%d]\n", y);
        } 
		else if (expected_width == -1)
            expected_width = (int)ft_strlen(data->map[y]);
		else if ((int)ft_strlen(data->map[y]) != expected_width)
		{
            error->square = TRUE;
            ft_printf("ERROR: Line width mismatch at [%d]\n", y);
        }
        y++;
    }
}


void	error_check(t_error *error, t_data *data)
{
	int flag = FALSE;
	t_data *cp;

	cp = copy_data(data);
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
	ft_printf("\n[%d][%d][%d][%d][%d][%d][%d]\n",	error->empty, 
													error->square,
													error->walls,
													error->overflow,
													error->v_path,
													error->bad_char,
													error->bad_map);
	if (flag == TRUE)
//		off_destroy(data);								
		ft_printf("\n");
}