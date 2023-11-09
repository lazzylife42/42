/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:58:47 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/30 23:28:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	print_array(t_data *data)
{
	int x;

	int y;
	y = 0;
	ft_printf("\n");
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			ft_printf("[%c]", data->map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void    flood(t_data *data, int x, int y, char old_char, char new_char)
{
	if (data->map[y][x] == old_char && y < data->map_height &&  x < data->map_width)
	{
		data->map[y][x] = new_char;
		flood(data, x + 1, y, old_char, new_char);
		flood(data, x - 1, y, old_char, new_char);
		flood(data, x, y + 1, old_char, new_char);
		flood(data, x, y - 1, old_char, new_char);
	}
}

void	error_path(t_error *error, t_data *data)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
				break ;
			x++;
		}
		if (data->map[y][x] == 'P')
			break ;
		y++;
	}
	i = 0;
	flood(data, x, y, 'P', '0');
	while (i++ < data->map_height)
	{
		flood(data, x, y, 'C', '0');
		flood(data, x, y, '0', 'C');	
	}
	flood(data, x, y, 'C', 'E');
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] != '1' && data->map[y][x] != 'E' && data->map[y][x] != 'B')
			{
				error->v_path = TRUE;
			}
			x++;
		}
		y++;
	}
	print_array(data);
}

t_data *copy_data(const t_data *source)
{
    t_data *copy = (t_data *)malloc(sizeof(t_data));
    if (copy == NULL)
        return NULL;
    copy->map_width = source->map_width;
    copy->map_height = source->map_height;

    copy->map = (char **)malloc(source->map_height * sizeof(char *));
    if (copy->map == NULL)
	{
        free(copy);
        return NULL;
    }

    int y = 0;
    while (y < source->map_height) 
	{
        copy->map[y] = (char *)malloc(source->map_width * sizeof(char));
        if (copy->map[y] == NULL) {
            for (int i = 0; i < y; i++) 
                free(copy->map[i]);
            free(copy->map);
            free(copy);
            return NULL;
        }
        int x = 0;
        while (x < source->map_width)
		{
            copy->map[y][x] = source->map[y][x];
            x++;
        }
        y++;
    }
    return copy;
}

void free_data(t_data *copy) 
{
    for (int y = 0; y < copy->map_height; y++)
	{
        free(copy->map[y]);
    }
    free(copy->map);
    free(copy);
}