/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:49:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/12 19:25:13 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_texture(char *tmp)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0
		|| ft_strncmp(tmp, "SO ", 3) == 0
		|| ft_strncmp(tmp, "EA ", 3) == 0
		|| ft_strncmp(tmp, "WE ", 3) == 0
		|| ft_strncmp(tmp, "F ", 2) == 0
		|| ft_strncmp(tmp, "C ", 2) == 0)
		return (1);
	else
		return (0);
}

int	ft_is_empty(char *tmp)
{
	size_t	i;

	i = 0;
	if (tmp == NULL)
		return (0);
	if (ft_strlen(tmp) == 1)
		return (1);
	while (tmp[i] != '\n')
	{
		if (ft_isspace(tmp[i]))
			return (1);
		i++;
	}
	return (0);
}

int	set_map(char *arg, char **argv, t_cube *cube)
{
	/* get_map_start(cube->map, arg); */
	get_map_height(cube->map, arg);
	get_map_width(cube->map, arg);
	map_renderer_init(cube, argv);
	return (0);
}

/* void	get_map_start(t_map *map, char *arg) */
/* { */
/* 	int		fd; */
/* 	int		count; */
/* 	char	*tmp; */

/* 	count = 0; */
/* 	fd = open(arg, O_RDONLY); */
/* 	if (fd == -1) */
/* 		ft_error(RED "Error\nCould not open file\n" RST); */
/* 	tmp = get_next_line(fd); */
/* 	while (tmp != NULL) */
/* 	{ */
/* 		if (ft_strlen(tmp) == 1) */
/* 		{ */
/* 			tmp = get_next_line(fd); */
/* 			continue ; */
/* 		} */
/* 		if (is_part_of_map(tmp) == -1 && ft_is_empty(tmp) == 1) */
/* 		{ */
/* 			count++; */
/* 			tmp = get_next_line(fd); */
/* 			continue ; */
/* 		} */
/* 		else */
/* 			break ; */
/* 	} */
/* 	map->map_start = count; */
/* 	if (DEBUG == 1) */
/* 		printf("Map start is %d\n", map->map_start); */
/* 	close(fd); */
/* } */

void	get_map_height(t_map *map, char *arg)
{
	int			fd;
	int			count;
	int			misc;
	char		*tmp;

	count = 0;
	misc = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (ft_strlen(tmp) == 1)
		{
			misc++;
			tmp = get_next_line(fd);
			continue ;
		}
		if (is_part_of_map(tmp) == -1 && ft_is_empty(tmp) == 1)
		{
			misc++;
			tmp = get_next_line(fd);
			continue ;
		}
		count++;
		tmp = get_next_line(fd);
	}
	map->m_height = count;
	map->file_height = count + misc;
	if (DEBUG == 1)
		printf("Map start is %d\n", map->file_height);
	close(fd);
}

int	ft_strlen_wo_spaces(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			count++;
		i++;
	}
	return (count);
}

void	get_map_width(t_map *map, char *arg)
{
	int			fd;
	int			width;
	int			tmp_width;
	int			i;
	int			map_start;
	char		*tmp;

	tmp_width = 0;
	width = 0;
	i = 0;
	map_start = map->file_height - map->m_height;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nCould not open file\n" RST);
	while (i < map_start)
	{
		tmp = get_next_line(fd);
		i++;
	}
	if (i == map_start)
	{
		i = 0;
		while (tmp != NULL && i <= map->m_height)
		{
			tmp_width = ft_strlen_wo_spaces(tmp);
			/* if (DEBUG == 1) */
			/* { */
			/* 	printf("idx %d: tmp is %d, current is %d\n", i, tmp_width, width); */
			/* 	printf("tmp is %s\n", tmp); */
			/* } */
			if (tmp_width > width)
				width = tmp_width;
			i++;
			tmp = get_next_line(fd);
		}
	}
	map->m_width = width;
	/* if (DEBUG == 1) */
	/* 	printf("Map width is %d\n", map->m_width); */
	close(fd);
}

int	check_players(t_cube *cube)
{
	int		x;
	int		y;
	int		player;

	player = 0;
	y = 0;
	cube->map->player = (t_player *)malloc(sizeof(t_player));
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			if (ft_strncmp(&cube->map->m_mini_map[y][x], "N", 1) == 0)
				player++;
			else if (ft_strncmp(&cube->map->m_mini_map[y][x], "E", 1) == 0)
				player++;
			else if (ft_strncmp(&cube->map->m_mini_map[y][x], "W", 1) == 0)
				player++;
			else if (ft_strncmp(&cube->map->m_mini_map[y][x], "S", 1) == 0)
				player++;
			x++;
		}
		y++;
	}
	return (player);
}

void	print_wall(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < Y_RES)
	{
		x = 0;
		while (x < X_RES)
		{
			printf("%d", cube->map->m_wall[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	init_player(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	cube->map->player = (t_player *)malloc(sizeof(t_player));
	if (cube->map->player == NULL)
		ft_error(RED "Error\nMalloc Failed\n" RST);
	if (check_players(cube) > 1)
		ft_error(RED "Error\nThere should only be one player. Pls fix map.\n" RST);
	else if (check_players(cube) == 0)
		ft_error(RED "Error\nNo player found :'(. Pls fix map\n" RST);
	init_wall(cube); 
	while (y < cube->map->m_height)
	{
		x = 0;
		while (x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == 'N')
			{
				cube->map->player->p_pos_x = x * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_y = y * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_a = 0;
				cube->map->player->offset = 0;
				return ;
			}
			else if (cube->map->m_mini_map[y][x] == 'E')
			{
				cube->map->player->p_pos_x = x * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_y = y * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_a = 90;
				cube->map->player->offset = 0;
				return ;
			}
			else if (cube->map->m_mini_map[y][x] == 'S')
			{
				cube->map->player->p_pos_x = x * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_y = y * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_a = 180;
				cube->map->player->offset = 0;
				return ;
			}
			else if (cube->map->m_mini_map[y][x] == 'W')
			{
				cube->map->player->p_pos_x = x * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_y = y * MINI_SCALE + (MINI_SCALE / 2);
				cube->map->player->p_pos_a = 270;
				cube->map->player->offset = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	fill_m_wall(t_cube *cube, int px, int py, bool door)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINI_SCALE)
	{
		x = 0;
		while (x < MINI_SCALE)
		{
			if (door)
				cube->map->m_wall[y + py][x + px] = 1;
			else
				cube->map->m_wall[y + py][x + px] = 0;
			x++;
		}
		y++;
	}
}

void	init_wall(t_cube *cube)
{
	int	x;
	int	y;

	y = -1;
	while (++y < Y_RES)
	{
		x = -1;
		while (++x < X_RES)
			cube->map->m_wall[y][x] = 0;
	}
	y = -1;
	while (++y < cube->map->m_height)
	{
		x = -1;
		while (++x < cube->map->m_width)
		{
			if (cube->map->m_mini_map[y][x] == '1' || cube->map->m_mini_map[y][x] == 'D')
				fill_m_wall(cube, x * MINI_SCALE, y * MINI_SCALE, true);
			else if (cube->map->m_mini_map[y][x] == 'd')
				fill_m_wall(cube, x * MINI_SCALE, y * MINI_SCALE, false);
		}
	}
}
