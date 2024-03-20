/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:23:52 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 11:20:23 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ends_with_xpm(char *str)
{
	int		len;
	char	*extension;
	int		ext_len;

	len = ft_strlen(str);
	extension = ".xpm";
	ext_len = ft_strlen(extension);
	if (len < ext_len
		|| ft_strncmp(str + len - ext_len, extension, ext_len) != 0)
		return (-1);
	else
		return (0);
}

int	xpm_mem_cmp(char *header, int fd)
{
	if (ft_memcmp(header, "/* XPM */", sizeof("/* XPM */")) == 10)
	{
		close(fd);
		return (0);
	}
	else
	{
		close(fd);
		ft_error(RED "Error\nNot an XPM file\n" RST);
		return (-1);
	}
}

int	is_xpm_file(const char *file_path)
{
	int				fd;
	char			header[sizeof("/* XPM */")];
	ssize_t			bytes_read;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error(RED "Error\nXPM file does not exist\n" RST);
		return (-1);
	}
	bytes_read = read(fd, header, sizeof(header));
	if (bytes_read < (ssize_t) sizeof(header))
	{
		close(fd);
		ft_error(RED "Error\nUnable to read xpm file\n" RST);
		return (-1);
	}
	if (xpm_mem_cmp(header, fd) == -1)
		return (-1);
	else
		return (0);
}
