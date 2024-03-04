/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/01 19:14:53 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_cube *cube)
{
	cube->text = (t_text *)malloc(sizeof(t_text));
	cube->text->t_img[0] = (t_img *)malloc(sizeof(t_img));
	cube->text->t_img[0]->img = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/textures/redbrick.xpm",
	&cube->text->t_width, &cube->text->t_height);
}

int get_texture_color(t_cube *cube, int text_id, t_vec pos)
{
    // Obtenir les coordonnées du pixel dans la texture
    int tex_x = (int)(pos.x * cube->text[text_id].t_width);
    int tex_y = (int)(pos.y * cube->text[text_id].t_height);

    // Assurez-vous que les coordonnées restent dans les limites de la texture
    tex_x = (tex_x < 0) ? 0 : (tex_x >= cube->text[text_id].t_width) ? cube->text[text_id].t_width - 1 : tex_x;
    tex_y = (tex_y < 0) ? 0 : (tex_y >= cube->text[text_id].t_height) ? cube->text[text_id].t_height - 1 : tex_y;

    // Accéder à la texture spécifique dans le tableau de textures
    t_img *texture = cube->text[text_id].t_img[0]; // Supposons que vous utilisez la première texture dans le tableau

    // Calculer l'indice dans les données de texture
    int tex_index = tex_y * texture->line_length + tex_x * (texture->bits_per_pixel / 8);

    // Accéder aux données de la texture pour obtenir la couleur du pixel
    char *pixel_address = texture->addr + tex_index;
    int color = *((int*)pixel_address);

    // À ce stade, vous avez la couleur du pixel
    printf("R: %d | G: %d | B: %d\n", (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);

    return color; // Retournez la couleur du pixel si nécessaire
}



