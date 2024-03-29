/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:46:46 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/14 18:25:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# ifdef __linux__
    # define MINILIBX_DIR "lib/minilibx-linux"
# else
    # define MINILIBX_DIR "lib/minilibx"
# endif

# include <mlx.h>
# include "lib/libft/libft.h"

#define WIDTH 232
#define HEIGHT 300


#endif


