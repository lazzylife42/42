/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/04 23:49:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_cube *cube)
{
	int		i;
	int		t_num;
	char	*file_path;

	i = 0;
	t_num = 4;
	cube->text = (t_text *)malloc(sizeof(t_text));
	if (cube->text == NULL)
		return (0);
	cube->text->t_img = (t_img *)malloc(sizeof(t_img) * t_num);
	if (cube->text->t_img == NULL)
	{
		free(cube->text);
		return (0);
	}
    cube->text->t_width = 300;
    cube->text->t_height = 300;
	while (i < t_num)
	{
		file_path = ft_strjoin("xpm/textures/text0", ft_itoa(i));
		ft_strlcpy(ft_strrchr(file_path, '\0'), ".xpm", 5);
		cube->text->t_img[i].img = mlx_xpm_file_to_image(cube->mlx_ptr,
				file_path, &cube->text->t_width, &cube->text->t_height);
        cube->text->t_img[i].addr = mlx_get_data_addr(cube->text->t_img[i].img, &cube->text->t_img[i].bits_per_pixel,
            &cube->text->t_img[i].line_length, &cube->text->t_img[i].endian);
		if (cube->text->t_img[i].img == NULL)
		{
			free(file_path);
			free(cube->text->t_img);
			free(cube->text);
			return (0);
		}
		free(file_path);
		i++;
	}
	return (1);
}

int	get_texture_color(t_cube *cube, int text_id, t_vec pos)
{
    int     color;
    int     x;
    int     y;
    int     bpp;
    int     endian;

    if (text_id < 0 || text_id >= 4 || cube->text[text_id].t_img == NULL)
        return (0);
    x = (int)pos.x;
    y = (int)pos.y;
    if (x < 0 || x >= cube->text[text_id].t_width || y < 0 || y >= cube->text[text_id].t_height)
        return (0);
    bpp = cube->text[text_id].t_img->bits_per_pixel;
    endian = cube->text[text_id].t_img->endian;

    int index = (y * cube->text[text_id].t_img->line_length) + (x * (bpp / 8));

    color = *(unsigned int *)(cube->text[text_id].t_img->addr + index);

    if (endian == 1) {
        color = ((color & 0xFF) << 24) | ((color & 0xFF00) << 8) | ((color >> 8) & 0xFF00) | ((color >> 24) & 0xFF);
    }
    // int r = (color >> 16) & 0xFF;
    // int g = (color >> 8) & 0xFF;
    // int b = color & 0xFF;
    // // Afficher les valeurs des composantes R, G et B pour le débogage
    // printf("R: %d, G: %d, B: %d\n", r, g, b);
    return (color);
}


int map_x(int value, int texture_width, int wall_width)
{
    return value * wall_width / texture_width;
}

int map_y(int value, int texture_height, int wall_height)
{
    return value * wall_height / texture_height;
}

void draw_textures(t_cube *cube, t_vec start, t_vec end, int texture_id)
{
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = (start.x < end.x) ? 1 : -1;
    int sy = (start.y < end.y) ? 1 : -1;
    int err = dx - dy;
    int e2;
    int max_iter = dx + dy;

    int texture_width = cube->text[texture_id].t_width;
    int texture_height = cube->text[texture_id].t_height;
    int wall_width = abs(end.x - start.x);
    int wall_height = abs(end.y - start.y);

    while (max_iter--)
    {
        if (start.x >= 0 && start.x < X_RES && start.y >= 0 && start.y < Y_RES)
        {
            // Convertir les coordonnées de texture en fonction de la position dans la ligne
            int texture_x = map_x(end.x - start.x, texture_width, wall_width);
            int texture_y = map_y(end.y - start.y, texture_height, wall_height);

            // Obtenir la couleur de la texture et dessiner le pixel
            int texture_color = get_texture_color(cube, texture_id, (t_vec){texture_x, texture_y});
            mlx_pixel(cube->img, start, texture_color);
        }
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            start.y += sy;
        }
        if (start.x == end.x && start.y == end.y)
            break;
    }
}









