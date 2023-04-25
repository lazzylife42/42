/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/25 14:18:20 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFF_SIZE 4096

char	*get_next_line(int fd)
{
	size_t		newline_index = 0;
	ssize_t 	ret;
	char		*line;
	char	*buff;

	buff = malloc(sizeof(char) * BUFF_SIZE);
	line = NULL;

	while (read(fd, &buff[newline_index], 1) > 0)
	{
//		newline_index = find_newline_index(buff);
		if (buff[newline_index] != '\0' && buff[newline_index] == '\n')
		{
			printf("\n--------------------------------------------------\n");
			split_line(&buff, &line, newline_index);
			return (line);
		}
		else if(buff[newline_index] == '\n'&& buff[newline_index] == '\0')
		{

			ret = read(fd, &buff[newline_index], 1);
			if (ret == -1)
				return (NULL);
			if (ret == 0)
			{
				line = return_all(buff);
				break;
			}
		}
		newline_index++;
	}
//	return (line);
}

/*	retourne line et reset le buffer */
size_t	split_line(char **buff, char **line, size_t newline_index)
{
	char	*temp;
	int		len;

	if (newline_index < 0)
		return (0);
/*	Termine la string *buff par \0 a la fin de la ligne */
	(*buff)[newline_index] = '\0';
/*	Renvoie une erreur si il ne peut pas copier *buff dans *line */
	if (!(*line = ft_strdup(*buff)))
		return (-1);
/*	Essaye d'affecter (*buff + newline_index) a len, free *buff si !len */
	len = ft_strlen(*buff) + newline_index + 1;
	if (!len)
	{
		free(*buff);
		*buff = NULL;
		return (1);
	}
/*	Essaye de copier la line dans temp, retourne une erreur si !temp*/
	if (!(temp = ft_strdup(*buff + newline_index + 1)))
		return (-1);
	free(*buff);
	*buff = temp;
	return (1);
}

int		find_newline_index(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*	*/

char	*return_all(char *buff)
{

}

