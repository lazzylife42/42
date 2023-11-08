/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_rev_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:46:54 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/08 17:16:47 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int start;
	int end;
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
			i++;
		while (i >= 0)
		{
			while (av[1][i] == ' ' || av[1][i] == '\t' || av[1][i] == '\0')
				i--;
			end = i;
			while (av[1][i] != ' ' && av[1][i] && av[1][i] != '\t')
				i--;
			start = i + 1;
			int flag;
			flag = start;
			while (start <= end)
			{
				write(1 , &av[1][start++], 1);
			}
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}
