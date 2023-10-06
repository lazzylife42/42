/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:33:15 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/06 14:28:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix(t_stack **a, t_stack **b)
{	
	int size;
	int max_num;
	int max_bits;
	int	i;
	int j;

	size = ft_llen(*a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;	
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			int num = (*a)->data;
			if (((num >> i)&1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		i++;
		while ((*b) != NULL)
			pa(a, b);
	}
}