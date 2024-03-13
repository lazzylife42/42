/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:59:36 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/09 16:45:41 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../cub3d.h" */

/* int	is_within_walls(t_map *map) */
/* { */
/* 	int	i; */
/* 	int	len; */
/* 	int	wall; */

/* 	i = 0; */
/* 	wall = 0; */
/* 	printf("test 1st line is %s\n", map->m_mini_map[i]); */
/* 	while (i < map->m_height) */
/* 	{ */
/* 		len = ft_strlen(map->m_mini_map[i]); */
/* 		printf("1st line is %s\n", map->m_mini_map[i]); */
/* 		printf("len is %d\n", len); */
/* 		printf("line %d: 1st nbr is %d\n", i, map->m_mini_map[i][0]); */
/* 		printf("line %d: last nbr is %d\n", i, map->m_mini_map[i][len - 1]); */
/* 		if (map->m_mini_map[i][0] != '1' || map->m_mini_map[i][len - 1] != '1') */
/* 			wall = 1; */
/* 		else */
/* 			wall = 0; */
/* 		i++; */
/* 	} */
/* 	return (wall); */
/* } */
