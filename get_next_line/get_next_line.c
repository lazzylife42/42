/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/27 20:53:22 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static int		newline_index;
	char			*line;
	char			*buff;
	static char		*backup;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	newline_index = find_newline_index(buff, newline_index);

	while (buff[newline_index] != '\0')
	{

		if (buff[newline_index] == '\n')
		{
			split_line(&buff, &line, newline_index);
			return (line);
		}
/*		if (buff[newline_index] == '\0')
		{
			free(buff);
			break;
		}*/
		newline_index++;
	}
	return (NULL);
/*
	if (read(fd, &buff[newline_index], BUFFER_SIZE) < 0)
	{
		return (NULL);
	}
*/	
			/*
			if(buff[newline_index] == '\n'&& buff[newline_index] == '\0')
			{
				free(buff);
			}
			*/	
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
	{
		return (-1);
	}
/*	Essaye d'affecter (*buff + newline_index) a len, free *buff si !len */
	len = ft_strlen(*buff) + newline_index + 1;
	if (!len)
	{
		free(*buff);
		*buff = NULL;
		return (1);
	}
/*	Essaye de copier la line dans temp, retourne une erreur si !temp*/
	if (!(temp = ft_strdup(*buff + newline_index + 2)))
		return (-1);
	free(*backup);
	backup = &temp; // problme par la
	return (1);
}

int		find_newline_index(char *buff, int newline_index)
{
	int	i;

	if (buff[newline_index] == '\0')
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
