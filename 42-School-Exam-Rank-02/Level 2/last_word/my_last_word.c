/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_last_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:45:08 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/08 13:05:15 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int count_space(char *str)
{
	int i = 0;
	int res = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
			res = i;
		i++;
	}
	return res;
}

int	main(int ac, char **av)
{
	int i = count_space(av[1]);
	i++;
	while (av[1][i] != ' ' && av[1][i])
	{
		write(1, &av[1][i], 1);
		i++;
	}
	return (0);
}
