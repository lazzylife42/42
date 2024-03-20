/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:03:26 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/10 16:15:49 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_empty_file(int fd)
{
	char	buff[1];
	int		bytes_read;

	bytes_read = read(fd, buff, sizeof(buff));
	if (bytes_read == -1)
	{
		close(fd);
		ft_error(RED "Error\nCould not read file\n" RST);
	}
	if (bytes_read == 0)
		ft_error(RED "Error\nWoops..File is empty\n" RST);
	close(fd);
	return (0);
}

int	check_extension(char *arg, char *extension)
{
	char	*dot;

	dot = ft_strrchr(arg, '.');
	if (!dot)
	{
		ft_error_long(RED "Error\nExtension missing in the file.\n" RST,
			RED "Please ensure the file has the extension\n" RST);
		return (1);
	}
	if (dot && ft_strcmp(dot, extension) != 0)
	{
		if (ft_strcmp(extension, ".cub") == 0)
			ft_error_long(RED "Error\nLa carte est introuvable.\n" RST,
				RED "Verifiez l'extension < .cub >\n" RST);
		else if (ft_strcmp(extension, ".xpm") == 0)
			ft_error_long(RED "Error\nLa texture est introuvable.\n" RST,
				RED "Verifiez l'extension < .xpm >\n" RST);
		return (1);
	}
	return (0);
}

int	check_args(int argc)
{
	if (argc != 2)
		ft_error(RED "Bad Args :\n" GRN "Try : <" BLU "./cube" GRN "> <" BLU
			" map/\'your_chosen _map\'" GRN ">\n" RST);
	return (0);
}

int	check_existing_file(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error_long(RED "Error\nLa carte est introuvable.\n" RST,
			RED "Verifiez le nom du fichier.\n" RST);
	check_empty_file(fd);
	close(fd);
	return (0);
}

int	check_map_file(char *arg)
{
	char	*extension;

	extension = ".cub";
	if (check_extension(arg, extension) == 0 && check_existing_file(arg) == 0)
		return (0);
	else
		return (-1);
}
