/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:14:34 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/07 16:24:39 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*cpy

	len = ft_strlen(src);
	if (src == NULL)
		return (NULL);
	cpy = (char *)malloc((len + 1) * sizeof(char);
	i = 0:
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return(cpy)
}
