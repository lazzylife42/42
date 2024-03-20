/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:07:23 by smonte-e          #+#    #+#             */
/*   Updated: 2024/03/19 20:37:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loadscreen(t_cube *cube)
{
	cube->img->img = mlx_new_image(cube->mlx_ptr, X_RES, Y_RES);
	cube->load->l_img = mlx_xpm_file_to_image(cube->mlx_ptr, LOADSCREEN,
			&cube->load->l_width, &cube->load->l_height);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->load->l_img, 0,
		0);
}

char	*generate_filename(int i)
{
	char	*base_filename;
	char	*itoa;

	base_filename = (char *)malloc(sizeof(char) * 50);
	if (!base_filename)
		exit(EXIT_FAILURE);
	ft_strlcpy(base_filename, "xpm/melt_xpm/melt", 20);
	if (i < 9)
		ft_strlcat(base_filename, "0", 50);
	itoa = ft_itoa(i + 1);
	ft_strlcat(base_filename, itoa, 50);
	ft_strlcat(base_filename, ".xpm", 50);
	free(itoa);
	return (base_filename);
}

void	load_melt_textures(t_cube *cube)
{
	int		i;
	char	*base_filename;

	i = 0;
	while (i < 31)
	{
		base_filename = generate_filename(i);
		cube->load->melt[i] = mlx_xpm_file_to_image(cube->mlx_ptr,
				base_filename, &cube->load->l_width, &cube->load->l_height);
		if (!cube->load->melt[i])
		{
			free(base_filename);
			exit(EXIT_FAILURE);
		}
		free(base_filename);
		i++;
	}
}

void	load_transition(t_cube *cube)
{
	int	frame_index;

	frame_index = 0;
	while (frame_index < 31)
	{
		mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr,
			cube->load->melt[frame_index], 0, 0);
		mlx_do_sync(cube->mlx_ptr);
		frame_index++;
	}
	mlx_mouse_move(cube->win_ptr, X_RES / 2, Y_RES / 2);
}
