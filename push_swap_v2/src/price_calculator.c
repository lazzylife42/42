/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:33:01 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/28 22:51:06 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refresh_price(t_stack *stack)
{
	int	pos;
	pos = 0;
	while (stack != NULL)
	{
		stack->next_to_move = FALSE;
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

static void find_min_max_data(t_stack *stack, int *min_data, int *max_data) 
{
	int current_min;
	int current_max;
	t_stack *current;
	
	current_min = INT_MAX;
	current_max = INT_MIN;
	current = stack;
	while (current != NULL) {
		if (current->data < current_min) {
			current_min = current->data;
		}
		if (current->data > current_max) {
			current_max = current->data;
		}
		current = current->next;
	}
	*min_data = current_min;
	*max_data = current_max;
}

void refresh_next(t_stack *stack) 
{
	int min_data;
	int max_data;
	int min_price;
	t_stack *min_element;
	t_stack *current;
	
	find_min_max_data(stack, &min_data, &max_data);
	min_price = INT_MAX;
	min_element = NULL;
	current = stack;
	while (current != NULL)
	{
		if (current->data == min_data && current->price < min_price) 
		{
			min_price = current->price;
			min_element = current;
		}
		current = current->next;
	}
	current = stack;
	while (current != NULL)
	{
		if (current == min_element) 
		{
			current->next_to_move = TRUE;
//			printf("Element with min data to move: [%d] $%d (%d)\n", current->data, current->price, current->next_to_move);
		} else 
		{
			current->next_to_move = FALSE;
		}
		current = current->next;
	}
}

int	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}