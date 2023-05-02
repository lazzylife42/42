/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/05/02 17:11:31 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



char	*get_next_line(int fd)
{
	static int		newline_index;
	char			*line;
	char			*buff;
//	char			*backup;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	line = NULL;

	while (read(fd, &buff[newline_index], 1) > 0)
	{
		if (buff[newline_index] != '\0' && buff[newline_index] == '\n')
		{
			split_line(&buff, &line, newline_index);
			return (line);
		}
		else if(buff[newline_index] == '\n'&& buff[newline_index] == '\0')
		{
			free(buff);
			break;
		}
/*		else if(buff[newline_index] == '\n'&& buff[newline_index] == '\0')
		{
			return (NULL);

			ret = read(fd, &buff[newline_index], 1);
			if (ret == -1)
				return (NULL);
			if (ret == 0)
			{
				return_all(buff, line);
				break;
			}
		}*/
		newline_index++;
	}
	return (NULL);
}

/*	retourne line et reset le buffer */
int	split_line(char **buff, char **line,char *backup, int newline_index)
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
	buff = &temp; // problme par la
	return (1);
}

int		find_newline_index(char *buff)
{
	int	i;

	if (buff[newline_index] == '\n')
		i = newline_index;
	else
		i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*	Renvoie ce qu'il reste dans buff */

int	return_all(char *buff, char *line)
{
//	int		newline_index;

	if (!(*buff))
	{
		if (!(line = ft_strdup("")))
			return (-1);
		return (0);
	}
//	if ((newline_index = find_newline_index(buff)) >= 0)
//		return (split_line(buff, line, newline_index));
	else
	{
		*line = *buff;
//		*buff = NULL;
		return (0);
	}
}
