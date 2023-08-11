/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/11 23:38:04 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	ssize_t newline_index;
	static char *buff;
	char *line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buff = gnl_read(fd, buff);
	if (!buff || buff == NULL)
		return (NULL);
	newline_index = find_newline_index(buff);
	if (newline_index < 0)
	{
		free(buff);
		return (NULL);
	}
	line = malloc(sizeof(char) * (newline_index + 1));
	if (!line)
	{
		free(line);	
		free(buff);
		return (NULL);
	}
	return (copy_line(buff, line, newline_index));
}

char *copy_line(char *buff, char *line, int newline_index)
{
	ft_strlcpy(line, buff, newline_index + 1);
	ft_strlcpy(buff, &buff[newline_index + 1], ft_strlen(buff) - newline_index);
	return (line);
}

char *gnl_read(int fd, char *buff)
{
	ssize_t bytes_readed;
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE));
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
