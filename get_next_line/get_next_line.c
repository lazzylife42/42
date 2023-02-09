/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:46:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/01/13 18:20:06 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_read(int fd, char *res);
char	*ft_gnl_get_line(char *buffer);
char	*ft_gnl_remove_old_line(char *buffer);


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	//1. read from fd and add to string
	//2. extract from stash to line
	//3. clean up stash

	return (line);
}

char	*ft_gnl_remove_free(char *buffer)
{
	free(buffer);
	return (NULL);
}
