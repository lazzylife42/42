/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:57:10 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/19 12:16:59 by smonte-e         ###   ########.fr       */
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
}   t_mlx_data;

/*  INPUT   */

int handle_imput(int keysym, t_mlx_data *data);

#endif