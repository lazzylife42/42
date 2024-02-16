/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:07:23 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/16 01:06:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loadscreen(t_cube *cube)
{
	cube->load = malloc(sizeof(t_load));
	cube->img->img = mlx_new_image(cube->mlx_ptr, X_RES, Y_RES);
	cube->load->l_img = mlx_xpm_file_to_image(cube->mlx_ptr, LOADSCREEN,
			&cube->load->l_width, &cube->load->l_height);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->load->l_img, 0,
		0);
}

void load_melt_textures_a(t_cube *cube)
{
    cube->load->melt[0] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt01.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[1] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt02.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[2] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt03.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[3] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt04.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[4] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt05.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[5] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt06.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[6] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt07.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[7] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt08.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[8] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt09.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[9] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt10.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[10] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt11.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[11] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt12.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[12] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt13.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[13] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt14.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[14] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt15.xpm", &cube->load->l_width, &cube->load->l_height);
}

void load_melt_textures_b(t_cube *cube)
{
 	cube->load->melt[15] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt16.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[16] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt17.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[17] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt18.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[18] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt19.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[19] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt20.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[20] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt21.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[21] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt22.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[22] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt23.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[23] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt24.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[24] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt25.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[25] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt26.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[26] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt27.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[27] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt28.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[28] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt29.xpm", &cube->load->l_width, &cube->load->l_height);
    cube->load->melt[29] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/melt_xpm/melt30.xpm", &cube->load->l_width, &cube->load->l_height);
}

void load_transition(t_cube *cube)
{
    int frame_index;

    frame_index = 0;
	load_melt_textures_a(cube);
	load_melt_textures_b(cube);
    while (frame_index < 30)
    {
        mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->load->melt[frame_index], 0, 0);
		mlx_do_sync(cube->mlx_ptr);
        frame_index++;
    }
}
