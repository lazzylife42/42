/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:40:26 by smonte-e          #+#    #+#             */
/*   Updated: 2023/01/13 18:47:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nb_elem, size_t size_elem);
char	*ft_strndup(char *buffer, size_t end);
char	*ft_gnl_strjoin(char *line, char *buff);
int		ft_gnl_strchr(char *str);

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *buffer, size_t end)
{
	
}


