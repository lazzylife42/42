/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:57:10 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/18 22:03:10 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX
# define FT_MLX

# ifdef __linux__
    # define MINILIBX_DIR "lib/minilibx-linux"
# else
    # define MINILIBX_DIR "lib/minilibx"
# endif

# include <mlx.h>
# include "lib/libft/libft.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct  s_mlx_data
{
    void    *mlx;
    void    *mlx_win;
}   t_mlx_data;

/*  INPUT   */

int handle_imput(int keysym, t_mlx_data *data);

#endif