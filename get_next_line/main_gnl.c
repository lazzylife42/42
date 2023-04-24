/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:24:23 by smonte-e          #+#    #+#             */
/*   Updated: 2023/04/24 23:38:32 by sab              ###   ########.fr       */
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
	while (RUN < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
				printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		RUN++;
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}