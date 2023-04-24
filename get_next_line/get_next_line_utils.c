/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:42:30 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/24 23:33:56 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Retourne la longeur de la string */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*	Duplique la string */

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

