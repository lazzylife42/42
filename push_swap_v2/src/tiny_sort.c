/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:47:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/28 22:28:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*find_highest(t_stack *node)
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
