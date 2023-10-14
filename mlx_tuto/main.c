/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:58:19 by sab               #+#    #+#             */
/*   Updated: 2023/10/14 18:26:21 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct  s_data
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         width;   // Ajoutez ces membres
    int         height;  // Ajoutez ces membres
}               t_data;

int main(void)
{
    void *mlx;
    void *mlx_win;
    t_data img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 232, 300, "Coucou!");

    // Chargez votre image XPM
    img.img = mlx_xpm_file_to_image(mlx, "img.xpm", &img.width, &img.height);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
