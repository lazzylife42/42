/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:02:15 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/22 17:53:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_cube *cube)
{
	cube->img->text[0] = mlx_xpm_file_to_image(cube->mlx_ptr, "xpm/textures/redbrick.xpm",
		&cube->img->t_width, &cube->img->t_height);
}

