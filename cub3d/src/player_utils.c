/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:58:07 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/15 19:02:04 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_players(t_cube *cube)
{
	int		x;
	int		y;
	int		player;
	char	current_char;

	player = 0;
	y = -1;
	cube->map->player = allocate_mem_player(cube);
	while (++y < cube->map->m_height)
	{
		x = -1;
		while (++x < cube->map->m_width)
		{
			current_char = cube->map->m_mini_map[y][x];
			if (current_char == 'N' || current_char == 'E'
				|| current_char == 'S' || current_char == 'W')
			{
				cube->map->player->p_pos_x = x;
				cube->map->player->p_pos_y = y;
				player++;
			}
		}
	}
	return (player);
}

void	error_players(t_cube *cube)
{
	if (check_players(cube) > 1)
		ft_error(RED "Error\nThere should only be one player.\n" RST);
	else if (check_players(cube) == 0)
		ft_error(RED "Error\nNo player found :'(.\n" RST);
}

void	set_player_position(t_cube *cube, int x, int y, char direction)
{
	cube->map->player->p_pos_x = x * MINI_SCALE + (MINI_SCALE / 2);
	cube->map->player->p_pos_y = y * MINI_SCALE + (MINI_SCALE / 2);
	if (direction == 'N')
		cube->map->player->p_pos_a = 0;
	else if (direction == 'E')
		cube->map->player->p_pos_a = 90;
	else if (direction == 'S')
		cube->map->player->p_pos_a = 180;
	else if (direction == 'W')
		cube->map->player->p_pos_a = 270;
	cube->map->player->offset = 0;
}

t_player	*allocate_mem_player(t_cube *cube)
{
	if (cube->map->player != NULL)
	{
		free(cube->map->player);
		cube->map->player = NULL;
	}
	cube->map->player = (t_player *)malloc(sizeof(t_player));
	if (cube->map->player == NULL)
		ft_error(RED "Error\nMalloc Failed\n" RST);
	return (cube->map->player);
}
