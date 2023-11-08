/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:59:52 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/08 10:53:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strrev.h"

int main(int ac, char **av)
{
	char *s1;
	char *s2;

	s1 = ft_strrev(av[1]);
	s2 = my_ft_strrev(av[1]);
	printf("strrev :%s\nmy_strr:%s\n", s1, s2);
	return (0);
}
