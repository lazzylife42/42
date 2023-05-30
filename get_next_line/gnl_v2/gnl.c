/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:59:08 by sab               #+#    #+#             */
/*   Updated: 2023/05/30 15:38:48 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

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
			return (NULL);
	}
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buff);
			free(line);
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

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int find_newline_index(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char *ft_substr(char *src, int pos, int len)
{
	char *dest = NULL;
	if (len > 0)
	{
		dest = (char *)malloc(len + 1);
		ft_strlcat(dest, src + pos, len);
	}
	return dest;
}

char *ft_strdup(const char *src)
{
	char *new;
	size_t i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t res;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize > i)
		res = ft_strlen((char *)src) + i;
	else
		res = ft_strlen((char *)src) + dstsize;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}