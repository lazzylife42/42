/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/18 14:00:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rgb	*final_check_textures(char *texture, t_textures *textures)
{
	char	**colors;
	t_rgb	*el_color;

	el_color = NULL;
	colors = NULL;
	if (find_commas(texture) == 2)
	{
		colors = split_to_rgb(texture);
		if (colors == NULL)
		{
			free_textures(textures);
			ft_error(RED "Error\nSplit error\n" RST);
		}
		if (validate_rgb_format(colors) != 0)
			ft_error(RED "Error\nRGB should be 3 numbers\n" RST);
		el_color = allocate_rgb_mem();
		digit_check(colors);
		check_colors(colors, el_color);
		free_colors(colors);
	}
	else if (find_commas(texture) == 1)
		ft_error(RED "Error\nRGB should be 3 numbers\n" RST);
	else
		ft_error(RED "Error\nNo colors...\n" RST);
	return (el_color);
}

void	check_texture_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_long(RED "Error\nCould not load texture\n" RST,
			RED "Check if file exists or is corrupted\n" RST);
	else
		close(fd);
}

void	init_texture_path(t_textures *textures)
{
	if (textures->no != NULL)
		is_xpm_file(textures->no);
	if (textures->so != NULL)
		is_xpm_file(textures->so);
	if (textures->ea != NULL)
		is_xpm_file(textures->ea);
	if (textures->we != NULL)
		is_xpm_file(textures->we);
	if (textures->f != NULL)
		textures->f_color = final_check_textures(textures->f, textures);
	if (textures->c != NULL)
		textures->c_color = final_check_textures(textures->c, textures);
}

int	assign_textures(t_textures *textures, int fd)
{
	textures_null(textures);
	find_cardinal(fd, textures);
	if (textures->no == NULL || textures->so == NULL
		|| textures->we == NULL || textures->ea == NULL
		|| textures->f == NULL || textures->c == NULL)
		ft_error_long(RED "Error\nMissing Textures or Colors.\n" RST,
			RED "Pls load correct map...\n" RST);
	else
	{
		close(fd);
		init_texture_path(textures);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_textures(char *av, t_cube *cube, t_textures *textures)
{
	int			fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(RED "Error\nLa carte est introuvable.\n" RST);
	else
	{
		assign_textures(textures, fd);
		cube->text = NULL;
		if (!init_textures(cube, textures))
			return (1);
	}
	return (0);
}
