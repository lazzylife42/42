/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:49:53 by sab               #+#    #+#             */
/*   Updated: 2023/05/30 15:38:04 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

char 	*get_next_line(int fd);
char 	*ft_substr(char *src, int pos, int len);
int 	find_newline_index(char *buff);
size_t 	ft_strlen(const char *str);
size_t 	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t 	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif