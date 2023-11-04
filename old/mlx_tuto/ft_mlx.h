/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:57:10 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/19 16:10:26 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX
# define FT_MLX

# include "lib/minilibx/mlx.h"
# include "lib/libft/libft.h"

typedef struct  s_mlx_data
{
    void    *mlx;
    void    *mlx_win;
	int		*width;
	int		*height;
	int 	sprite[1][576];
}   t_mlx_data;

/*  INPUT			*/

int 	handle_imput(int keysym, t_mlx_data *data);

/*	RENDER FRAME	*/

void	render_map(t_mlx_data data, int map[][]);

#endif