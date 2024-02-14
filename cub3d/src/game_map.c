/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:49:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/14 19:07:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cube *cube)
{
	int		x;
	int		y;

	y = 0;
	cube->map->player = (t_player *)malloc(sizeof(t_player));
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == 'P')
			{
				cube->map->player->p_pos_x = x * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_y = y * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_a = 0; //gérer ici l'orientation
				printf("Player{%d;%d}\n", cube->map->player->p_pos_x, cube->map->player->p_pos_y);
				return ;
			}
			x++;
		}
		y++;
	}
}

