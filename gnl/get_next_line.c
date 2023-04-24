/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/24 16:17:21 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFF_SIZE 500000

char	*get_next_line(int fd)
{
	size_t		newline_index = 0;
	char				*line;
	static char			*buff;

	buff = malloc(sizeof(char) * BUFF_SIZE);

	while (fd)
	{
/*	Coppie le text dans buff */
		while (read(fd, &buff[newline_index], 1))
		{
			while(find_newline_index(buff) > 0)
			{
				newline_index = find_newline_index(buff);
				gpt_split_line(&buff, &line, newline_index);
//				printf("Buff Line : [%s]\n", buff);
			}
//			printf("Buff : [%c]\n", buff[newline_index]);
			newline_index++;	
//			if (read(fd, &buff[newline_index], 1) == 0)
//				break;
		}
//		printf("oui ! \n");
		return (line);
		break;
	}
	return (NULL);
}


/*	retourne line et reset le buffer */

size_t	split_line(char **buff, char **line, size_t newline_index)
{
	char	*temp;
	int		len;
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
	
	// à completer

	return (buff);
}

size_t gpt_split_line(char **buff, char **line, size_t newline_index)
{
    char    *temp;
    int     len;
    size_t  i;

    // Terminate the string at the newline index
    (*buff)[newline_index] = '\0';

    // Allocate memory for the line
    *line = malloc(sizeof(char) * (newline_index + 1));
    if (!*line)
        return (-1);

    // Copy the line into the newly allocated memory
    i = 0;
    while (i < newline_index)
    {
        (*line)[i] = (*buff)[i];
        i++;
    }
    (*line)[i] = '\0';

    // Calculate the length of the remaining part of the buffer
    len = ft_strlen(*buff + newline_index + 1);

    // Allocate memory for the remaining part of the buffer
    temp = malloc(sizeof(char) * (len + 1));
    if (!temp)
        return (-1);

    // Copy the remaining part of the buffer into the newly allocated memory
    ft_strcpy(temp, *buff + newline_index + 1);

    // Free the original buffer and assign the new buffer to the pointer
    free(*buff);
    *buff = temp;

    return (1);
}