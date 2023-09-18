/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:24:44 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/18 15:23:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	char	*str;

	//printf("Rentrer la string :");
	//scanf("%s", str);
	ft_printf(" %u %u %u ", 1, 2, 3);
	printf("\n\n");
	return (0);
}
