/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/04 16:53:17 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_cube *cube)
{
    int     i;
    int     t_num;
    char    *file_path;

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
    while (i < t_num)
    {
        file_path = ft_strjoin("xpm/textures/text0", ft_itoa(i));
        ft_strlcpy(ft_strrchr(file_path, '\0'), ".xpm", 5);
        cube->text->t_img[i].img = mlx_xpm_file_to_image(cube->mlx_ptr, file_path,
                                                    &cube->text->t_width, &cube->text->t_height);
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



// int get_texture_color(t_cube *cube, int text_id, t_vec pos)
// {
//     // Obtenir les coordonnées du pixel dans la texture
//     int tex_x = (int)(pos.x * cube->text[text_id].t_width);
//     int tex_y = (int)(pos.y * cube->text[text_id].t_height);

//     // Assurez-vous que les coordonnées restent dans les limites de la texture
//     tex_x = (tex_x < 0) ? 0 : (tex_x >= cube->text[text_id].t_width) ? cube->text[text_id].t_width - 1 : tex_x;
//     tex_y = (tex_y < 0) ? 0 : (tex_y >= cube->text[text_id].t_height) ? cube->text[text_id].t_height - 1 : tex_y;

//     // Accéder à la texture spécifique dans le tableau de textures
//     t_img *texture = cube->text[text_id].t_img[0]; // Supposons que vous utilisez la première texture dans le tableau

//     // Calculer l'indice dans les données de texture
//     int tex_index = tex_y * texture->line_length + tex_x * (texture->bits_per_pixel / 8);

//     // Accéder aux données de la texture pour obtenir la couleur du pixel
//     char *pixel_address = texture->addr + tex_index;
//     int color = *((int*)pixel_address);

//     // À ce stade, vous avez la couleur du pixel
//     printf("R: %d | G: %d | B: %d\n", (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);

//     return color; // Retournez la couleur du pixel si nécessaire
// }



