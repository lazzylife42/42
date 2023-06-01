/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/06/01 19:48:48 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	int newline_index;
	int bytes_readed;
	static char *buff = NULL;
	char *line = NULL;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	bytes_readed = 1;
	if (buff == NULL)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
		{
			free(buff);
			return (NULL);
		}
	}
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		newline_index = find_newline_index(buff);
		if (newline_index >= 0)
		{
			line = copy_line(buff, line, newline_index);
			return (line);
		}
	}
	free(buff);
	return (NULL);
}

char *copy_line(char *buff, char *line, int newline_index)
{
	line = malloc(sizeof(char) * (newline_index + 1));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(line, buff, newline_index + 1);
	ft_strlcpy(buff, &buff[newline_index + 1], ft_strlen(buff) - newline_index);
	return (line);
}