/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:41:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_cube *cube)
{
	int		i;
	char	*file_path;

	i = 0;
	cube->text = (t_text *)malloc(sizeof(t_text));
	if (cube->text == NULL)
		return (0);
	cube->text->t_img = (t_img *)malloc(sizeof(t_img) * TEXTURES_NUM);
	if (cube->text->t_img == NULL)
	{
		free(cube->text);
		return (0);
	}
    // cube->text->t_width = 300;
    // cube->text->t_height = 300;
	while (i < TEXTURES_NUM)
	{
		file_path = ft_strjoin("xpm/textures/text0", ft_itoa(i));
		ft_strlcpy(ft_strrchr(file_path, '\0'), ".xpm", 5);
		cube->text->t_img[i].img = mlx_xpm_file_to_image(cube->mlx_ptr,
				file_path, &cube->text->t_img[i].width, &cube->text->t_img[i].height);
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

    if (text_id < 0 || text_id >= TEXTURES_NUM || cube->text->t_img[text_id].img == NULL)
        return (0);
    x = (int)pos.x;
    y = (int)pos.y;
    if (x < 0 || x >= cube->text->t_img[text_id].width || y < 0 || y >= cube->text->t_img[text_id].height)
        return (0);
    bpp = cube->text->t_img[text_id].bits_per_pixel;
    endian = cube->text->t_img[text_id].endian;

    int index = (y * cube->text->t_img[text_id].line_length) + (x * (bpp / 8));

    color = *(unsigned int *)(cube->text->t_img[text_id].addr + index);

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

// void draw_textures(t_cube *cube, t_vec start, t_vec end, int texture_id)
// {
//     // Calcul de la hauteur de la ligne sur l'écran
//     int lineHeight = abs(end.y - start.y);

//     // Récupération des dimensions de la texture
//     // int texture_width = cube->text[texture_id].t_width;
//     int texture_height = cube->text[texture_id].t_height;

//     // Calcul de l'incrément de la coordonnée de texture par pixel
//     double step = 1.0 * texture_height / lineHeight;

//     // Calcul de la position de départ de la texture en fonction de la position verticale sur l'écran
//     double texture_pos = (start.y - Y_RES / 2 + lineHeight / 2) * step;

//     // Parcours de chaque pixel de la ligne sur l'écran
//     for (int y = start.y; y < end.y; y++)
//     {
//         // Conversion de la position de texture en entier et gestion du débordement
//         int tex_y = (int)texture_pos & (texture_height - 1);

//         // Mise à jour de la position de texture pour le prochain pixel
//         texture_pos += step;

//         // Obtention de la couleur de la texture à partir des coordonnées de texture
//         int texture_color = get_texture_color(cube, texture_id, (t_vec){150, tex_y});

//         // Dessin du pixel avec la couleur de la texture
//         mlx_pixel(cube->img, (t_vec){start.x, y}, texture_color);
//     }
// }

int calculate_tex_x(t_cube *cube, int texture_id)
{
    // Calcul de la position exacte du mur touché sur l'écran
    double wallX;
    if (cube->ray->side == 0) // Si le rayon a frappé une face est/ouest
        wallX = cube->map->player->p_pos_y + cube->ray->p_walld * cube->ray->dir.y;
    else // Si le rayon a frappé une face nord/sud
        wallX = cube->map->player->p_pos_x + cube->ray->p_walld * cube->ray->dir.x;
    wallX -= floor(wallX); // Retirer la partie entière pour obtenir la partie fractionnaire

    // Calcul de la coordonnée x de la texture en fonction de la position exacte du mur touché
    int tex_x = (int)(wallX * (double)cube->text->t_img[texture_id].width);
    if ((cube->ray->side == 0 && cube->ray->dir.x > 0) || (cube->ray->side == 1 && cube->ray->dir.y < 0)) // Ajustement pour certaines orientations
        tex_x = cube->text->t_img[texture_id].width - tex_x - 1;

    return tex_x;
}


void draw_textures(t_cube *cube, t_vec start, t_vec end, int texture_id)
{
    // Récupération des informations de texture à partir de la structure cube
    int texture_height = cube->text->t_img[texture_id].height;
    
    // Calcul de la hauteur de la ligne sur l'écran
    int lineHeight = abs(end.y - start.y);

    // Calcul de l'incrément de la coordonnée de texture par pixel
    double step = 1.0 * texture_height / lineHeight;

    // Calcul de la position de départ de la texture en fonction de la position verticale sur l'écran
    double texture_pos = (start.y - Y_RES / 2 + lineHeight / 2) * step;

    // Parcours de chaque pixel de la ligne sur l'écran
    for (int y = start.y; y < end.y; y++)
    {
        // Conversion de la position de texture en entier et gestion du débordement
        int tex_y = (int)texture_pos & (texture_height - 1);

        // Mise à jour de la position de texture pour le prochain pixel
        texture_pos += step;

        // Obtention de la couleur de la texture à partir des coordonnées de texture
        int tex_x = calculate_tex_x(cube, texture_id); // Fonction à implémenter pour calculer tex_x
        int texture_color = get_texture_color(cube, texture_id, (t_vec){tex_x, tex_y});

        // Affichage temporaire pour vérifier
        // printf("pos : {%d;%d}(%d)\n", start.x, y, texture_color);
        // (void)texture_color;
        mlx_pixel(cube->img, (t_vec){start.x, y}, texture_color);
    }
}



