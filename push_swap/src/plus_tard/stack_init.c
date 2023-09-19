/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:56:06 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/04 01:35:55 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	long ft_atol(const char *str)
{
	int		i;
	int		signe;
	long	cache;

	i = 0;
	signe = 1;
	cache = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		cache = cache * 10 + (str[i] - 48);
		i++;
	}	
	return (signe * cache);	
}

void	stack_init(t_stack_node **a, char **array)
{
	long	number;
	while (*array)
	{
		number = ft_atol(array);
		if (number > INT_MAX || number < INT_MIN)
			error_free(a, array);
		if (error_repetition(a, (int)number))
			error_free(a, array);
		append_node(a, (int)number);
		array++;
	}
	
}