/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:47:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/21 18:43:04 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

List	*find_highest(List *list)
{
	int				highest;
	List	*highest_node;

	if (NULL == list)
		return (NULL);
	highest = INT_MIN;
	while (list)
	{
		if (list->data > highest)
		{
			highest = list->data;
			highest_node = list;
		}
		list = list->next;
	}
	return (highest_node);
}

int	list_sorted(List *list)
{
	if (NULL == list)
		return (1);
	while (list->next)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

void	tiny_sort(List **a)
{
	List	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
/*
void	handle_five(List **a, List **b)
{
	while (list_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a);
	}
}
*/
