/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:06:05 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/03 12:19:38 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rotone(char *str)
{
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Y') || (*str >= 'a' && *str <= 'y'))
			ft_putchar(*str + 1);
		else if (*str == 'Z' || *str == 'z')
			ft_putchar(*str - 25);
		else
			ft_putchar(*str);
		str++;
	}
}


int main(int argc, char **argv)
{
	if (argc == 2)
		ft_rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
