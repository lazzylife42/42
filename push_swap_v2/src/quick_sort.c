/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:30:58 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/04 15:35:35 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pll(t_stack *a, t_stack *b)
{
	ft_lprint(a);
	ft_lprint(b);
	ft_printf("\n");
}

int	init_pivot(t_stack *a)
{
	int pivot;
	
	set_p_first(a, 0);
	set_pivot_at(a, ft_llen(a) - 1);
	set_p_last(a, ft_llen(a));
	while (a->pivot != TRUE || a->next == NULL)
		a = a->next;
	pivot = a->data;
	return (pivot);
}

void quick_sort(t_stack **a, t_stack **b)
{
	int len;
	int pivot;
	int count = 0;

	pll(*a, *b);


	while (count < 10)
	{
		len = ft_llen(*a);
		pivot = init_pivot(*a);
		ft_printf("\nPivot : %d\n", pivot);
		while (len > 0)
		{
			if ((*a)->data > pivot)
				pb(a, b);
			else
				rra(a);
			len--;
		}
		len = ft_llen(*b);
		pivot = init_pivot(*b);
		ft_printf("\nPivot : %d\n", pivot);
		while (len > 0)
		{
			if ((*b)->data < pivot)
				pa(a, b);
			else
				rrb(b);
			len--;
		}
	count++;
	while ((*b) != NULL)
		pa(a, b);
	}
	pll(*a, *b);
}