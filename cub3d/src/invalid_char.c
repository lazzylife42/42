/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:25:22 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/13 15:27:06 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_char(char letter)
{
	if (letter == 'N' || letter == 'S' || letter == 'E'
		|| letter == 'W' || letter == '0'
		|| letter == ' ' || letter == '1' || letter == 'D' || letter == '\n')
		return (1);
	return (0);
}

int	check_valid_chars_in_line(char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (!is_valid_char(line[j]))
			return (0);
		j++;
	}
	return (1);
}

void	handle_invalid_char(char *line)
{
	ft_error(RED "Error\nInvalid map file\n" RST);
	free(line);
}

char	*has_invalid(int fd, char *buff)
{
	if (!check_valid_chars_in_line(buff))
	{
		handle_invalid_char(buff);
		buff = get_next_line(fd);
	}
	return (buff);
}
