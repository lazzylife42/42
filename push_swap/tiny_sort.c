/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:47:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/09 22:08:04 by smonte-e         ###   ########.fr       */
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

void	tiny_sort(t_stack **a, t_stack **b)
{
	while (ft_llen(*a) > 3)
		pb(a, b);
	tiny_sort_3(a);
	while (*b)
		pa(a, b);
}

void	tiny_sort_3(t_stack **a)
{
	if (ft_llen(*a) == 2)
		sa(a);
	else if (ft_llen(*a) == 3)
	{
		if ((*a)->data > (*a)->next->data
			&& (*a)->data < (*a)->next->next->data)
			sa(a);
		else if ((*a)->data > (*a)->next->data
			&& (*a)->data > (*a)->next->next->data)
		{
			sa(a);
			ra(a);
		}
		else if ((*a)->data < (*a)->next->data
			&& (*a)->data > (*a)->next->next->data)
			rra(a);
		else if ((*a)->data > (*a)->next->data
			&& (*a)->next->data < (*a)->next->next->data)
			ra(a);
		else if ((*a)->data < (*a)->next->data
			&& (*a)->data < (*a)->next->next->data &&
			(*a)->next->data > (*a)->next->next->data)
		{
			sa(a);
			rra(a);
		}
	}
}
