/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/24 02:17:13 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFF_SIZE 500000

char	*get_next_line(int fd)
{
	size_t		newline_index = 0;
	char		*line;
	static char *buff;

	buff = malloc(sizeof(char) * BUFF_SIZE);

	while (fd)
	{
/*	Coppie le text dans buff */
		while (read(fd, &buff[newline_index], 1))
		{
			if(find_newline_index(buff) > 0)
			{
				newline_index = find_newline_index(buff);
				split_line(&buff, &line, newline_index);

			}
			printf("Buff : [%c]\n", buff[newline_index]);
			newline_index++;	
			if (read(fd, &buff[newline_index], 1) == 0)
				break;
		}
		printf("oui ! \n");
		return (line);

		break;
	}
	return (NULL);
}


/*	retourne line et reset le buffer */

size_t	split_line(char **backup, char **line, size_t newline_index)
{
	char	*temp;
	int		len;
/*	Termine la string *backup par \0 a la fin de la ligne */
	(*backup)[newline_index] = '\0';
/*	Renvoie une erreur si il ne peut pas copier *backup dans *line */
	if (!(*line = ft_strdup(*backup)))
		return (-1);
/*	Essaye d'affecter (*backup + newline_index) a len, free *backup si !len */
	len = ft_strlen(*backup + newline_index + 1);
	if (!len)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
/*	Essaye de copier la line dans temp, retourne une erreur si !temp*/
	if (!(temp = ft_strdup(*backup + newline_index + 1)))
		return (-1);
	free(*backup);
	*backup = temp;
	return (1);
}

/*	Coppie new_buff dans buff */

char	*keep_buff(char *buff, char *new_buff)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	while (buff[i] != '\0')
		i++;	
		while (new_buff[j] != '\0')
		{
			buff[i] = new_buff[j];
			i++;
			j++;
		}
	buff[i] = '\0';
	return (buff);
}

int		find_newline_index(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*	*/

char	*return_all(char *buff)
{
	
	// à completer

	return (buff);
}
