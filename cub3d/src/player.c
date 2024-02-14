/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:59:05 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/14 19:33:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	player_move(int keysym, t_cube *cube)
{
	if (keysym == 53)
		on_destroy(cube);
	else if (keysym == 123)
	{
		rotate_left(cube);
		// printf("Key : %d\n", keysym);
	}
	else if (keysym == 124)
	{
		rotate_right(cube);
		// printf("Key : %d\n", keysym);
	}
	else if (keysym == 13 || keysym == 126)
	{
		move_up(cube);
		// printf("Key : %d\n", keysym);
	}
	else if (keysym == 0)
	{
		move_left(cube);
		// printf("Key : %d\n", keysym);
	}
	else if (keysym == 1 || keysym == 125)
	{
		move_down(cube);
		// printf("Key : %d\n", keysym);
	}
	else if (keysym == 2)
	{
		move_right(cube);
		// printf("Key : %d\n", keysym);
	}
	frame_render(cube);
	return (0);
}

void rotate_left(t_cube *cube)
{
    cube->map->player->p_pos_a -= 90 / MODULO_RATIO;
}

void rotate_right(t_cube *cube)
{
    cube->map->player->p_pos_a += 90 / MODULO_RATIO;
}

void move_up(t_cube *cube)
{
    int x, y;
    static int range = MODULO_RATIO;

    range++;
    if (range % MODULO_RATIO == 0)
    {
        y = 0;
        while (y < cube->map->m_height)
        {
            x = 0;
            while (x < cube->map->m_width)
            {
                if (cube->map->m_mini_map[y][x] == 'P' && cube->map->m_mini_map[y - 1][x] != '1' && y > 1)
                {
                    cube->map->m_mini_map[y - 1][x] = 'P';
                    cube->map->m_mini_map[y][x] = '0';
					cube->map->player->p_pos_y -= MINI_SCALE / MODULO_RATIO;
                    printf("pos{%d, %d}\n", cube->map->player->p_pos_x, cube->map->player->p_pos_y);
                    break;
                }
                x++;
            }
            y++;
        }
        range = 0;
        return;
    }
    cube->map->player->p_pos_y -= MINI_SCALE / MODULO_RATIO;
}

void move_left(t_cube *cube)
{
    int x, y;
    static int range = MODULO_RATIO;

    range++;
    if (range % MODULO_RATIO == 0)
    {
        y = 0;
        while (y < cube->map->m_height)
        {
            x = 0;
            while (x < cube->map->m_width)
            {
                if (cube->map->m_mini_map[y][x] == 'P' && cube->map->m_mini_map[y][x - 1] != '1' && x > 1)
                {
                    cube->map->m_mini_map[y][x - 1] = 'P';
                    cube->map->m_mini_map[y][x] = '0';
					cube->map->player->p_pos_x -= MINI_SCALE / MODULO_RATIO;
                    printf("pos{%d, %d}\n", cube->map->player->p_pos_x, cube->map->player->p_pos_y);
                    break;
                }
                x++;
            }
            y++;
        }
        range = 0;
        return;
    }
    cube->map->player->p_pos_x -= MINI_SCALE / MODULO_RATIO;
}

void move_down(t_cube *cube)
{
    int x, y;
    static int range = MODULO_RATIO;

    range++;
    if (range % MODULO_RATIO == 0)
    {
        y = cube->map->m_height - 1;
        while (y >= 0)
        {
            x = 0;
            while (x < cube->map->m_width)
            {
                if (cube->map->m_mini_map[y][x] == 'P' && y < cube->map->m_height - 1 && cube->map->m_mini_map[y + 1][x] != '1')
                {
                    cube->map->m_mini_map[y + 1][x] = 'P';
                    cube->map->m_mini_map[y][x] = '0';
					cube->map->player->p_pos_y += MINI_SCALE / MODULO_RATIO;
                    printf("pos{%d, %d}\n", cube->map->player->p_pos_x, cube->map->player->p_pos_y);
                    return;
                }
                x++;
            }
            y--;
        }
    }
    cube->map->player->p_pos_y += MINI_SCALE / MODULO_RATIO;
}

void move_right(t_cube *cube)
{
    int x, y;
    static int range = MODULO_RATIO;

    range++;
    if (range % MODULO_RATIO == 0)
    {
        y = 0;
        while (y < cube->map->m_height)
        {
            x = cube->map->m_width - 1;
            while (x >= 0)
            {
                if (cube->map->m_mini_map[y][x] == 'P' && x < cube->map->m_width - 1 && cube->map->m_mini_map[y][x + 1] != '1')
                {
                    cube->map->m_mini_map[y][x + 1] = 'P';
                    cube->map->m_mini_map[y][x] = '0';
					cube->map->player->p_pos_x += MINI_SCALE / MODULO_RATIO;
                    printf("pos{%d, %d}\n", cube->map->player->p_pos_x, cube->map->player->p_pos_y);
                    return;
                }
                x--;
            }
            y++;
        }
    }
    cube->map->player->p_pos_x += MINI_SCALE / MODULO_RATIO;
}
