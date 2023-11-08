/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstr_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:22:03 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/03 12:34:21 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void reverse_char(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			ft_putchar(*str + 32);
		else if (*str >= 'a' && *str <= 'z')
			ft_putchar(*str - 32);
		else
			ft_putchar(*str);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		reverse_char(av[1]);
	ft_putchar('\n');
	return (0);
}
