/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/12 11:57:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static char *buff;
	char *line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buff = gnl_read(fd, buff);
	if (!buff)
		return (NULL);
	line = gnl_get_line(buff);
	buff = gnl_remove_old_line(buff);
	return (line);
}

ssize_t	find_newline_index(char *buff)
{
	ssize_t i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *gnl_read(int fd, char *buff)
{
	ssize_t bytes_readed;
	
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buff);
			return (NULL);
		}
	}
	return(buff);
}

char	*gnl_get_line(char *buff)
{
	int		i;
	char	*str;

	if (!buff[0])
		return (NULL);
	i = find_newline_index(buff);
	if (i == -1)
		i = ft_strlen(buff);
	str = ft_strndup(buff, i);
	if (!str)
		return (NULL);
	return (str);
}

char	*gnl_remove_old_line(char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	i = find_newline_index(buff);
	if (i == -1)
	{
		free(buff);
		return (NULL);
	}
	str = (char *)ft_calloc(ft_strlen(buff) - i + 1, sizeof(char));
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	j = 0;
	while (buff[++i])
		str[j++] = buff[i];
	str[j] = '\0';
	free(buff);
	return (str);
}