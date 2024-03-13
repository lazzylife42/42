/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:50 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/12 18:40:17 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hexa(t_rgb *rgb)
{
	return (((rgb->r & 0xFF) << 16) + ((rgb->g & 0xFF) << 8) + (rgb->b & 0xFF));
}

// void	my_pixel_put(t_cube *cube, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = cube->img->addr + (y * cube->img->line_length
// 			+ x * (cube->img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	check_colors(char **colors, t_rgb *texture)
{
	if (colors[0] == NULL || colors[1] == NULL
		|| colors[2] == NULL)
	{
		free(colors);
		ft_error(RED "Error\nShould be 3 colors\n" RST);
	}
	else
	{
		texture->r = ft_atoi(colors[0]);
		printf("red is %d\n", texture->r);
		texture->g = ft_atoi(colors[1]);
		printf("green is %d\n", texture->g);
		texture->b = ft_atoi(colors[2]);
		printf("blue is %d\n", texture->b);
	}
	if ((texture->r < 0 || texture->r > 255)
		|| (texture->g < 0 || texture->g > 255)
		|| (texture->b < 0 || texture->b > 255))
		ft_error(RED "Error\nInt should be between 0 and 255\n" RST);
}

int	find_commas(char *texture)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (texture[i])
	{
		if (texture[i] == ',')
			commas++;
		i++;
	}
	return (commas);
}

int	count_words(char **colors)
{
	int	count;

	count = 0;
	while (*colors != NULL)
	{
		count++;
		colors++;
	}
	return (count);
}

void	digit_check(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i] != NULL)
	{
		j = 0;
		while (colors[i][j] != '\0')
		{
			if (!ft_isdigit(colors[i][j]))
				ft_error(RED "Error\nNot just integers\n" RST);
			j++;
		}
		i++;
	}
}
