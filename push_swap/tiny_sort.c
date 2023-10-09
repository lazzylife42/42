/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:47:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/09 16:10:44 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*find_highest(t_stack *node)
{
	int		highest;
	t_stack	*highest_node;

	if (node == NULL)
		return (NULL);
	highest = INT_MIN;
	while (node)
	{
		if (node->data > highest)
		{
			highest = node->data;
			highest_node = node;
		}
		node = node->next;
	}
	return (highest_node);
}

t_stack	*find_lowest(t_stack *node)
{
	int		lowest;
	t_stack	*lowest_node;

	if (node == NULL)
		return (NULL);
	lowest = INT_MAX;
	while (node)
	{
		if (node->data < lowest)
		{
			lowest = node->data;
			lowest_node = node;
		}
		node = node->next;
	}
	return (lowest_node);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
