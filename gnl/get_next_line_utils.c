/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:42:30 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/19 17:17:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] != (char)c)
	{
		if (ptr[i] == '\0')
			return (NULL);
		i++;
	}
	return (&ptr[i]);
}

char	*split_line(const char *buff)
{
	//à completer
	
	return (buff);
}

char	*keep_buff(char *buff, char *new_buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
		i++;	
		while (new_buff[i] != '\0')
		{
			buff[i] = new_buff[i];
			i++;
		}
	buff[i] = '\0';
	return (buff);
}

char	*return_all(char *buff)
{
	
	// à completer

	return (buff);
}