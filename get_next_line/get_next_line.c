/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/06/01 16:31:25 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	int newline_index;
	int bytes_readed;
	static char *buff = NULL;
	char *tmp = NULL;
	char *line = NULL;

	bytes_readed = 1;
	if (buff == NULL)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
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
			free(tmp);
			return (NULL);
		}
		newline_index = find_newline_index(buff);
		if (newline_index >= 0)
		{
			line = malloc(sizeof(char) * (newline_index + 1));
			ft_strlcpy(line, buff, newline_index + 1);
			tmp = malloc(sizeof(char) * (ft_strlen(buff) - newline_index));
			ft_strlcpy(tmp, &buff[newline_index + 1], ft_strlen(buff) - newline_index);
			free(buff);
			buff = tmp;
			return (line);
		}
	}
	free(buff);
	return (NULL);
}
