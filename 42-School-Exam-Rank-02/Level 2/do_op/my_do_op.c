/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:42:52 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/07 15:25:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	 main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf("%d", atoi(av[1]) + atoi(av[3]));
		else if (av[2][0] == '-')
			printf("%d", atoi(av[1]) - atoi(av[3]));
		else if (av[2][0] == 42)
			printf("%d", atoi(av[1]) * atoi(av[3]));
		else if (av[2][0] == '/')
			printf("%d", atoi(av[1]) / atoi(av[3]));
		else if (av[2][0] == '%')
			printf("op : %s\n%d",av[2], atoi(av[1]) % atoi(av[3]));
	}
	printf("\n");
	return 0;
}

