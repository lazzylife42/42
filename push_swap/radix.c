/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:33:15 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/06 20:11:45 by smonte-e         ###   ########.fr       */
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
			int num = (*a)->index;
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

void update_index(t_stack *head)
{
    t_stack *current;
	int index;
	
	current = head;
	index = 1;
    while (current != NULL)
    {
        current->index = index;
        index++;
        current = current->next;
    }
}

/*
void swap_nodes(t_stack *head, int index1, int index2)
{
	t_stack *node1 = NULL;
	t_stack *node2 = NULL;

	t_stack *current = head;

	while (current != NULL)
	{
		if (current->index == index1)
			node1 = current;
		else if (current->index == index2)
			node2 = current;
		current = current->next;
	}
	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

void radix_index(t_stack **a)
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
			int num = (*a)->index;
			if (((num >> i)&1) == 1)
			{
				swap_nodes(*a, (*a)->index, ft_llen(*a));
//				ra(a);
			}				
			else
				pb(a, b);
			j++;
		}
		i++;
		while ((*b) != NULL)
			pa(a, b);
	}
}
*/