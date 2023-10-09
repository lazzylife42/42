/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:33:15 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/09 18:47:09 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_pass(t_stack **a, t_stack **b, int bit)
{
	int	size;
	int	i;
	int	num;

	i = 0;
	size = ft_llen(*a);
	while (i < size)
	{
		num = (*a)->index;
		if (((num >> bit) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b != NULL)
		pa(a, b);
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_num;
	int	max_bits;
	int	i;

	max_num = ft_llen(*a) - 1;
	max_bits = 0;
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, i);
		i++;
	}
}

void	update_index(t_stack *head)
{
	t_stack	*current;
	int		index;

	index = 1;
	current = head;
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}
