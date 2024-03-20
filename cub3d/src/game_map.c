/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:49:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/19 15:15:08 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_map(char *arg, char **argv, t_cube *cube)
{
	if (!get_map_height(cube, arg, 0, 0))
		ft_error(RED "Error\n There is only one map...\n" RST);
	get_map_width(cube, arg);
	if (cube->map->m_height > (X_RES / MINI_SCALE)
		|| cube->map->m_width > (Y_RES / MINI_SCALE))
		ft_error(RED "Error\nMap too big\n" RST);
	map_renderer_init(cube, argv);
	return (0);
}

void	init_player(t_cube *cube)
{
	int	x;
	int	y;
	int	current_char;

	y = 0;
	init_wall(cube);
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			current_char = cube->map->m_mini_map[y][x];
			if (current_char == 'N' || current_char == 'E'
				|| current_char == 'S' || current_char == 'W')
			{
				set_player_position(cube, x, y, current_char);
				return ;
			}
			x++;
		}
		y++;
	}
}
