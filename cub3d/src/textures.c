/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/12 20:16:09 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_textures(t_textures *textures)
{
	printf("f is %s\n", textures->f);
	printf("c is %s\n", textures->c);
	if (textures->f_color == NULL && textures->c_color == NULL)
		return (4);
	else if (textures->f_color == NULL || textures->c_color == NULL)
		return (4);
	else
		return (4);
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

int	init_textures(t_cube *cube, t_textures *textures)
{
	int		i;
	char	*file_path;
	int		texture_count;

	i = 0;
	cube->text = (t_text *)malloc(sizeof(t_text));
	if (cube->text == NULL)
		return (0);
	texture_count = count_textures(textures);
	printf("texture count is %d\n", texture_count);
	cube->text->t_img = (t_img *)malloc(sizeof(t_img) * (texture_count + 2));
	if (cube->text->t_img == NULL)
	{
		free(cube->text);
		return (0);
	}
	while (i < texture_count)
	{
		file_path = get_texture_path(i, textures);
		cube->text->t_img[i].img = mlx_xpm_file_to_image(cube->mlx_ptr,
				file_path, &cube->text->t_img[i].width,
				&cube->text->t_img[i].height);
		cube->text->t_img[i].addr = mlx_get_data_addr(cube->text->t_img[i].img,
				&cube->text->t_img[i].bits_per_pixel,
				&cube->text->t_img[i].line_length,
				&cube->text->t_img[i].endian);
		if (cube->text->t_img[i].img == NULL)
		{
			free(cube->text->t_img);
			free(cube->text);
			return (0);
		}
		i++;
		printf("i:%d\n", i);
	}
	cube->text->t_img[i].img = mlx_xpm_file_to_image(cube->mlx_ptr,
			"xpm/textures3/text04.xpm", &cube->text->t_img[i].width,
			&cube->text->t_img[i].height);
	cube->text->t_img[i].addr = mlx_get_data_addr(cube->text->t_img[i].img,
			&cube->text->t_img[i].bits_per_pixel,
			&cube->text->t_img[i].line_length,
			&cube->text->t_img[i].endian);
			i++;
	cube->text->t_img[i].img = mlx_xpm_file_to_image(cube->mlx_ptr,
			"xpm/textures3/text05.xpm", &cube->text->t_img[i].width,
			&cube->text->t_img[i].height);
	cube->text->t_img[i].addr = mlx_get_data_addr(cube->text->t_img[i].img,
			&cube->text->t_img[i].bits_per_pixel,
			&cube->text->t_img[i].line_length,
			&cube->text->t_img[i].endian);
	return (1);
}

int	get_texture_color(t_cube *cube, int texture_id, t_vec pos)
{
	int	color;
	int	index;

	color = 0;
	if (cube == NULL || texture_id < 0 || texture_id >= TEXTURES_NUM
		|| cube->text == NULL || cube->text->t_img == NULL
		|| cube->text->t_img[texture_id].img == NULL)
		return (color);
	if (pos.x < 0 || pos.x >= cube->text->t_img[texture_id].width || pos.y < 0
		|| pos.y >= cube->text->t_img[texture_id].height)
		return (color);
	index = (pos.y * cube->text->t_img[texture_id].line_length) + (pos.x
			* (cube->text->t_img[texture_id].bits_per_pixel / 8));
	color = *(unsigned int *)(cube->text->t_img[texture_id].addr + index);
	if (cube->text->t_img[texture_id].endian == 1)
		color = ((color & 0xFF) << 24) | ((color & 0xFF00) << 8) | ((color >> 8) & 0xFF00) | ((color >> 24) & 0xFF);
	return (color);
}

void	draw_textures(t_cube *cube, t_vec start, t_vec end, int texture_id)
{
	int		y;
	float	ty;
	float	ty_step;
	int		color;
	int		texture_to_use;

	ty = 0;
	ty_step = (float)cube->text->t_img[texture_id].height / (float)(end.y
			- start.y);
	y = start.y;
	while (y < end.y)
	{
		if (cube->ray->hit == 2)
		{
			texture_to_use = 4;
			color = get_texture_color(cube, texture_to_use, (t_vec){(cube->ray->col
						% cube->text->t_img[texture_to_use].width), ty});
			mlx_pixel(cube->img, (t_vec){cube->ray->col, y}, color);
			ty += ty_step;
			y++;
		}
		else
		{
			texture_to_use = texture_id;
			if (cube->ray->side == 0)
			{
				if (cube->ray->dir.x > 0)
					texture_to_use = (texture_id + 1) % 4;
				else
					texture_to_use = (texture_id + 3) % 4;
			}
			else
			{
				if (cube->ray->dir.y > 0)
					texture_to_use = (texture_id + 2) % 4;
				else
					texture_to_use = texture_id;
			}
			color = get_texture_color(cube, texture_to_use, (t_vec){(cube->ray->col
						% cube->text->t_img[texture_to_use].width), ty});
			mlx_pixel(cube->img, (t_vec){cube->ray->col, y}, color);
			ty += ty_step;
			y++;	
		}	
	}
}
