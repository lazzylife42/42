/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/12 20:26:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ends_with_xpm(char *str)
{
	int		len;
	char	*extension;
	int		ext_len;

	len = ft_strlen(str);
	extension = ".xpm";
	ext_len = ft_strlen(extension);
	if (len < ext_len
		|| ft_strncmp(str + len - ext_len, extension, ext_len) != 0)
		return (-1);
	else
		return (0);
}

int	is_xpm_file(const char *file_path)
{
	int				fd;
	char			header[sizeof(XPM_MAGIC)];
	ssize_t			bytes_read;

	fd = open(file_path, O_RDONLY);
	printf("path is %s\n", file_path);
	printf("header is %lu\n", sizeof(header));
	printf("xpm_magic is %lu\n", sizeof(XPM_MAGIC));
	if (fd == -1)
	{
		ft_printf("unable to open %s\n", file_path);
		ft_error(RED "Error\nUnable to open file\n" RST);
		return (-1);
	}
	bytes_read = read(fd, header, sizeof(header));
	if (bytes_read < (ssize_t) sizeof(header))
	{
		close(fd);
		ft_error(RED "Error\nUnable to read file\n" RST);
		return (-1);
	}
	if (DEBUG == 1)
	{
		int mem_cpy = ft_memcmp(header, XPM_MAGIC, sizeof(XPM_MAGIC));
		printf("mem copy is %d\n", mem_cpy);
	}
	if (ft_memcmp(header, XPM_MAGIC, sizeof(XPM_MAGIC)) == 10)
	{
		close(fd);
		if (DEBUG == 1)
			printf(GRN "I am an xpm\n" RST);
		return (0);
	}
	else
	{
		close(fd);
		printf("header is %lu\n", sizeof(header));
		printf("xpm_magic is %lu\n", sizeof(XPM_MAGIC));
		ft_error(RED "Error\nNot an XPM file\n" RST);
		return (-1);
	}
}

t_rgb	*final_check_textures(char *texture)
{
	char	**colors;
	int		count;
	t_rgb	*el_color = NULL;

	if (find_commas(texture) == 2)
	{
		colors = ft_split(texture, ',');
		if (colors == NULL)
		{
			free(texture);
			texture = NULL;
		}
		count = count_words(colors);
		printf("count is %d\n", count);
		if (count != 3)
			ft_error(RED "CoucouError\nRGB should be 3 numbers\n" RST);
		el_color = malloc(count * sizeof(t_rgb));
		if (el_color == NULL)
			ft_error(RED "Error\nMalloc failed\n" RST);
		digit_check(colors);
		check_colors(colors, el_color);
		free(colors);
		// free(el_color);
	}
	else if (find_commas(texture) == 1)
		ft_error(RED "Error\nRGB should be 3 numbers\n" RST);
	else
		is_xpm_file(texture);
	return (el_color);
}

void	check_texture_exists(char *path)
{
	int	fd;

	printf("path is %s\n", path);
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
		final_check_textures(textures->no);
	if (textures->so != NULL)
		final_check_textures(textures->so);
	if (textures->ea != NULL)
		final_check_textures(textures->ea);
	if (textures->we != NULL)
		final_check_textures(textures->we);
	if (textures->f != NULL)
		textures->f_color = final_check_textures(textures->f);
	if (textures->c != NULL)
		textures->c_color = final_check_textures(textures->c);
}

int	assign_textures(t_textures *textures, int fd)
{
	textures_null(textures);
	find_cardinal(fd, textures);
	if (textures->no == NULL || textures->so == NULL
		|| textures->we == NULL || textures->ea == NULL
		|| textures->f == NULL || textures->c == NULL)
		ft_error_long(RED "Error\nMissing Textures.\n" RST,
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
		if (!init_textures(cube, textures))
			return (0);
		}
	return (0);
}
