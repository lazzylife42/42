/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:35:00 by smonte-e          #+#    #+#             */
/*   Updated: 2024/02/20 10:21:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec raycast(t_cube *cube)
{
    t_vec ray = {
        cube->map->player->p_pos_x ,
        cube->map->player->p_pos_y 
    };
    float ra = (cube->map->player->p_pos_a - 90) * M_PI / 180;
    float a_tan = 1 / tan(ra);
    float step_x, step_y;
    if (ra < M_PI)
    {
        ray.y = ((cube->map->player->p_pos_y / MINI_SCALE) * MINI_SCALE) - 0.0001;
        step_y = -MINI_SCALE / FINE_RATIO;
    }
    else
    {
        ray.y = ((cube->map->player->p_pos_y / MINI_SCALE) * MINI_SCALE) + MINI_SCALE;
        step_y = MINI_SCALE / FINE_RATIO;
    }
    step_x = step_y * a_tan;
    int mx, my, fov;

    fov = 0;
    while (fov < cube->map->m_height && fov < cube->map->m_width)
    {
        mx = ray.x * MINI_SCALE;
        my = ray.y * MINI_SCALE;

        // Vérifier si nous avons atteint les limites de la carte
        if (mx < 0 || mx >= cube->map->m_width || my < 0 || my >= cube->map->m_height)
            fov = cube->map->m_height * cube->map->m_width;
        if (cube->map->m_wall[ray.y * MINI_SCALE][mx])
            fov = cube->map->m_height * cube->map->m_width;
        if (cube->map->m_wall[my][ray.x * MINI_SCALE])
            fov = cube->map->m_height * cube->map->m_width;
        ray.x += cos(ra) * step_x;
        ray.y += sin(ra) * step_y;
        fov++;
    }

    return ray;
}
