/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:33:01 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/28 20:06:10 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_price(t_stack *stack)
{
	int	pos;
	pos = 0;
	while (stack != NULL)
	{
		if (pos == 0)
			stack->price = 0;
		else if (pos < ft_llen(stack) + 1 / 2)
			stack->price = pos;
		else
			stack->price = ft_llen(stack) + 1 / 2;
		pos++;
//		printf("pos : %d\nnext: %p\n", pos, stack->next);
		stack = stack->next;
	}
}