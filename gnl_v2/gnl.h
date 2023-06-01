/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:01:13 by sab               #+#    #+#             */
/*   Updated: 2023/05/17 17:17:39 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif



char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		find_newline_index(char *buff);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char 	*ft_substr(char *src,int pos,int len);
char	*ft_strdup(const char *src);

#endif