/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/06/01 17:00:27 by sab              ###   ########.fr       */
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

	bytes_readed = 1;
	if (buff == NULL)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
		{
			free_all(buff,line);
			return (NULL);
		}
	}
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free_all(buff,line);
			return (NULL);
		}
		newline_index = find_newline_index(buff);
		if (newline_index >= 0)
		{
			line = malloc(sizeof(char) * (newline_index + 1));
			ft_strlcpy(line, buff, newline_index + 1);
			ft_strlcpy(buff, &buff[newline_index + 1], ft_strlen(buff) - newline_index);
			return (line);
		}
	}
	free(buff);
	return (NULL);
}

void free_all(char *buff, char *line)
{
	free_all(buff,line);
	free(line);
}