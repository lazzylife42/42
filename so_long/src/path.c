/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:49:04 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/27 13:29:15 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#define MAX_ROWS 20
#define MAX_COLS 20

int visited[MAX_ROWS][MAX_COLS];

int rowOffset[] = {-1, 0, 1, 0};
int colOffset[] = {0, 1, 0, -1};

static int isValid(int x, int y, int width, int height) 
{
    return x >= 0 && x < width && y >= 0 && y < height;
}


static int canReachExit(char **map, int height, int width, int x, int y) 
{
    if (map[y][x] == 'E') 
    {
        return TRUE;  // We reached the exit
    }

    visited[y][x] = TRUE;

    for (int dir = 0; dir < 4; dir++) 
    {
        int newX = x + colOffset[dir];
        int newY = y + rowOffset[dir];

        if (isValid(newX, newY, height, width) && !visited[newY][newX] &&
            map[newY][newX] != 'P' && map[newY][newX] != 'C') 
        {
            if (canReachExit(map, height, width, newX, newY) == TRUE) 
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}


static int	find_pos(t_data *data)
{
	int x;
	int y;
	int pos[2];

	y = 0;
	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			x = 0;
			if (data->map[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y; 
				return *pos;
			}
			x++;
		}
		y++;
	}
	return (0);
}

void error_path(t_error *error, t_data *data)
{
    int pathExists;
    int pos[2];

    *pos = find_pos(data);

    // Réinitialisez le tableau 'visited' avant chaque appel à 'canReachExit'
    int y = 0;
    while (y < MAX_ROWS) {
        int x = 0;
        while (x < MAX_COLS) {
            visited[y][x] = FALSE;
            x++;
        }
        y++;
    }

    pathExists = canReachExit(data->map, data->map_height, data->map_width, pos[0], pos[1]);

    if (pathExists) {
        ft_printf("Un chemin existe.\n");
    } else {
        error->v_path = TRUE;
    }
}

