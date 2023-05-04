/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:24:23 by smonte-e          #+#    #+#             */
/*   Updated: 2023/05/02 17:23:43 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int	main(void)
{
	int		fd;
	char	*line;
	
	int RUN = 1;

	fd = open("test.txt", O_RDONLY);
	while (RUN)
	{
		line = get_next_line(fd);
		printf("%s", line);
		printf("\n-------\n");
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}