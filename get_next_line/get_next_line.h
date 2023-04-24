/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:49:53 by sab               #+#    #+#             */
/*   Updated: 2023/04/24 23:34:51 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif



char	*get_next_line(int fd);
char	*return_all(char *buff);
char	*ft_strdup(const char *src);
int		find_newline_index(char *backup);
size_t	split_line(char **backup, char **line, size_t newline_index);
size_t	ft_strlen(const char *s);

#endif