/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:14:16 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/24 20:33:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_move(int keysym, t_data *data)
{
	if (keysym == 53)
		on_destroy(data);
	else if (keysym == 13 || keysym == 126)
		move_up(data);
	else if (keysym == 0 || keysym == 123)
		move_left(data);
	else if (keysym == 1 || keysym == 125)
		move_down(data);
	else if (keysym == 2 || keysym == 124)
		move_right(data);
	map_renderer(data);
	return (0);
}

void	move_up(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{	
			if (data->map[y][x] == 'P' && data->map[y - 1][x] != '1' && y > 1)
			{
				if (data->map[y - 1][x] == '0')
				{
					data->map[y - 1][x] = 'P';
					data->map[y][x] = '0';
					break;
				}
				else if (data->map[y - 1][x] == 'C')
				{
					data->map[y - 1][x] = 'P';
					data->map[y][x] = '0';
					break;
				}
				else if (data->map[y - 1][x] == 'E')
				{
					data->map[y - 1][x] = 'P';
					data->map[y][x] = '0';
					break;
				}
			}
			x++;
		}
		y++;
	}
}

void	move_left(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{	
			if (data->map[y][x] == 'P' && data->map[y][x - 1] != '1' && x > 1)
			{
				if (data->map[y][x - 1] == '0')
				{
					data->map[y][x - 1] = 'P';
					data->map[y][x] = '0';
					break;
				}
				else if (data->map[y][x - 1] == 'C')
				{
					data->map[y][x - 1] = 'P';
					data->map[y][x] = '0';
					break;
				}
				else if (data->map[y][x - 1] == 'E')
				{
					data->map[y][x - 1] = 'P';
					data->map[y][x] = '0';
					break;
				}
			}
			x++;
		}
		y++;
	}
}

void move_down(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->map_height)
    {
        x = 0;
        while (x < data->map_width)
        {   
            if (data->map[y][x] == 'P' && y < data->map_height - 1 && data->map[y + 1][x] != '1')
            {
                if (data->map[y + 1][x] == '0')
                {
                    data->map[y + 1][x] = 'P';
                    data->map[y][x] = '0';
                    return; // Return after moving one cell down
                }
                else if (data->map[y + 1][x] == 'C')
                {
                    data->map[y + 1][x] = 'P';
                    data->map[y][x] = '0';
                    return; // Return after moving one cell down
                }
                else if (data->map[y + 1][x] == 'E')
                {
                    data->map[y + 1][x] = 'P';
                    data->map[y][x] = '0';
                    return; // Return after moving one cell down
                }
            }
            x++;
        }
        y++;
    }
}


void move_right(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{   
			if (data->map[y][x] == 'P' && x < data->map_width - 1 && data->map[y][x + 1] != '1')
			{
				if (data->map[y][x + 1] == '0')
				{
					data->map[y][x + 1] = 'P';
					data->map[y][x] = '0';
					break;
				}
				else if (data->map[y][x + 1] == 'C')
				{
					data->map[y][x + 1] = 'P';
					data->map[y][x] = '0';
					break;
				}
				else if (data->map[y][x + 1] == 'E')
				{
					data->map[y][x + 1] = 'P';
					data->map[y][x] = '0';
					break;
				}
			}
			x++;
		}
		y++;
	}
}
