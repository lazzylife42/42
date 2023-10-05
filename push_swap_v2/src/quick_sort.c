/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:30:58 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/05 15:36:22 by smonte-e         ###   ########.fr       */
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

	
	if ((*a)->set_p_first < ((*a)->set_p_last))
	{
		set_pivot_at(*a, ft_llen(*a) - 1);
		
	}



	pll(*a, *b);
}