/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/20 16:10:39 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	count;
	char	*text;
	char	*buff;
	char	*new_buff;

if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,))
{
	/* code */
}


/*
	while (fd != NULL)
	{
		if(ft_strchr(text, '\n') == NULL)
		{
			if (read(fd, text, count) > 0)
				keep_buff(buff, new_buff);
		}
		else if (ft_strchr(text, '\n') == '\n')
		{
			split_line(buff);
		}	
	}
	return (return_all(buff));
*/
}

/*	retourne line et reset le buffer */

int		*split_line(char **line, char **backup, char *next_line);
{
	line = malloc(sizeof((next_line - backup +1)));
	

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

/*	*/

char	*return_all(char *buff)
{
	
	// à completer

	return (buff);
}
