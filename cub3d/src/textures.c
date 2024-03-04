/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/04 16:06:06 by smonte-e         ###   ########.fr       */
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
    cube->text = (t_text *)malloc(sizeof(t_text) * t_num);
    while (i < t_num)
    {
        cube->text[i].t_img = (t_img *)malloc(sizeof(t_img));
        if (cube->text[i].t_img == NULL)
            return (0);
        file_path = ft_strjoin("xpm/textures/0", ft_itoa(i));
        ft_strlcpy(ft_strrchr(file_path, '\0'), ".xpm", 5);
        cube->text[i].t_img = mlx_xpm_file_to_image(cube->mlx_ptr, file_path,
                                                    &cube->text[i].t_width, &cube->text[i].t_height);
        free(file_path);
        i++;
    }
	return (1);
}
