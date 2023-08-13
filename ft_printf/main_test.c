/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:24:44 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/13 19:39:06 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	char	*str;

	printf("Rentrer la string :");
	scanf("%s", str);
	ft_printf("ft_printf         :%s", str);
	printf("\n\n");
	return (0);
}
