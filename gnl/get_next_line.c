/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:18:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/20 00:04:43 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	//ssize_t fd;
	size_t	count;
	char	*text;
	char	*buff;
	char	*new_buff;

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
			free(buff);
		}	
	}
	return (return_all(buff));
}

