/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:03:36 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 14:05:39 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	texture_to_mlx(t_cube *cube, int i, char *file_path)
{
	cube->text->t_img[i].img = mlx_xpm_file_to_image(cube->mlx_ptr,
			file_path, &cube->text->t_img[i].width,
			&cube->text->t_img[i].height);
	if (cube->text->t_img[i].img == NULL)
	{
		free(cube->text->t_img);
		free(cube->text);
		return (0);
	}
	cube->text->t_img[i].addr = mlx_get_data_addr(cube->text->t_img[i].img,
			&cube->text->t_img[i].bits_per_pixel,
			&cube->text->t_img[i].line_length,
			&cube->text->t_img[i].endian);
	return (1);
}

int	load_default_textures(t_cube *cube, int index)
{
	char	*default_textures[2];
	int		i;

	i = 0;
	default_textures[0] = "xpm/textures3/text04.xpm";
	default_textures[1] = "xpm/textures3/text05.xpm";
	while (i < 2)
	{
		if (!texture_to_mlx(cube, index + i, default_textures[i]))
			return (0);
		i++;
	}
	return (1);
}

int	load_textures(t_cube *cube, t_textures *textures, int texture_count)
{
	int		i;
	char	*file_path;

	i = 0;
	while (i < texture_count)
	{
		file_path = get_texture_path(i, textures);
		if (!texture_to_mlx(cube, i, file_path))
			return (0);
		i++;
	}
	return (1);
}

char	*get_texture_path(int index, t_textures *texture)
{
	char	*file_path;

	file_path = NULL;
	if (index == 0)
		file_path = texture->no;
	else if (index == 1)
		file_path = texture->so;
	else if (index == 2)
		file_path = texture->we;
	else if (index == 3)
		file_path = texture->ea;
	return (file_path);
}
