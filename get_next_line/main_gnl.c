/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:24:23 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/11 14:39:40 by smonte-e         ###   ########.fr       */
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
		printf("\n");
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}