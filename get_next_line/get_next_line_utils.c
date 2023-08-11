/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:42:30 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/11 23:55:43 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void			*ptr;
	size_t			i;
	unsigned char	c;

	ptr = malloc(nb_elem * size_elem);
	if (!ptr)
		return (NULL);
	i = 0;
	c = '\0';
	while (i < (nb_elem * size_elem))
	{
		((char *)ptr)[i] = c;
		i++;
	}
	return (ptr);
}