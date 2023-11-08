/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:58:11 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/08 11:15:45 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int t1[256];
	int i = 0;

	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			t1[(int)av[2][i]] = 1;
			i++;
		}
		i = 0;
		while(av[1][i] != '\0')
		{
			if (t1[(int)av[1][i]] == 1)
			{
				write(1, &av[1][i], 1);
				t1[(int)av[1][i]] = 2;
			}
			i++;
		}
		write(1, "\n", 1);
	}	
	return (0);
}
