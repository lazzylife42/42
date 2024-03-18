/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:50:37 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 09:52:02 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_rgb_format(char **colors)
{
	int	count;

	count = count_words(colors);
	if (count == 3)
		return (0);
	else
		return (1);
}

t_rgb	*allocate_rgb_mem(void)
{
	t_rgb	*el_color;

	el_color = malloc(3 * sizeof(t_rgb));
	if (el_color == NULL)
		ft_error(RED "Error\nMalloc failed\n" RST);
	return (el_color);
}

char	**split_to_rgb(char *texture)
{
	char	**colors;

	colors = ft_split(texture, ',');
	if (colors == NULL)
	{
		free(texture);
		texture = NULL;
	}
	return (colors);
}

char	*trim_spaces(char *texture)
{
	char	*start;
	char	*end;
	char	*i;
	char	*j;

	start = texture;
	end = texture + ft_strlen(texture - 1);
	while (ft_isspace((unsigned char)*start))
		start++;
	while (end > start && ft_isspace((unsigned char)*end))
	{
		if (*(end - 1) == ' ' && *end == '\n')
			break ;
		end--;
	}
	i = start;
	j = start;
	while (*j)
	{
		if (*j != ' ' || (*(j + 1) == '\n' && *(j + 2) == '\0'))
			*i++ = *j;
		j++;
	}
	*i = '\0';
	return (start);
}
