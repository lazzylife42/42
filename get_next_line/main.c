/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:35:17 by sabino            #+#    #+#             */
/*   Updated: 2023/01/13 17:50:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%d", line);
		free(line);
	}

	return (0);
}
