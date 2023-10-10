/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:47:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/10 13:45:21 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	four_sort(t_stack **a, t_stack **b)
{
	while ((*a)->data == find_highest(*a)->data
		|| (*a)->data == find_lowest(*a)->data
		|| !stack_sorted(*a))
	{
		ra(a);
		if ((*a)->data == find_highest(*a)->data)
		{
			pb(a, b);
			tiny_sort(a);
			pa(a, b);
			ra(a);
			break ;
		}
		else if ((*a)->data == find_lowest(*a)->data)
		{
			pb(a, b);
			tiny_sort(a);
			pa(a, b);
			break ;
		}
	}
}

void	five_sort(t_stack **a, t_stack **b)
{
	while ((*a)->data == find_highest(*a)->data
		|| (*a)->data == find_lowest(*a)->data
		|| !stack_sorted(*a))
	{
		ra(a);
		if ((*a)->data == find_highest(*a)->data)
		{
			pb(a, b);
			four_sort(a, b);
			pa(a, b);
			ra(a);
			break ;
		}
		else if ((*a)->data == find_lowest(*a)->data)
		{
			pb(a, b);
			four_sort(a, b);
			pa(a, b);
			break ;
		}
	}
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_llen(*a);
	if (len == 2)
		ra(a);
	else if (len == 3)
		tiny_sort(a);
	else if (len == 4)
		four_sort(a, b);
	else if (len == 5)
		five_sort(a, b);
}
