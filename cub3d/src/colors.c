/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:58:50 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 09:25:18 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_hexa(t_rgb *rgb)
{
	return (((rgb->r & 0xFF) << 16) + ((rgb->g & 0xFF) << 8) + (rgb->b & 0xFF));
}

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
		texture->g = ft_atoi(colors[1]);
		texture->b = ft_atoi(colors[2]);
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
	if (colors == NULL || colors[0] == NULL)
		ft_error(RED "Error\n" RST);
	while (colors[count] != NULL)
		count++;
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
				ft_error(RED "Error\nShould be int between 0 and 255\n" RST);
			j++;
		}
		i++;
	}
}
