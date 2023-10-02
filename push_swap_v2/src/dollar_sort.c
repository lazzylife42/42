/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:36:03 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/02 14:22:25 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int set_pivot(t_stack *a)
{
	int	pos;
	int	pivot;
	
	pos = 0;
	while (pos < (ft_llen(a) + 1 )/ 2)
	{
		pos++;
		a = a->next;
	}
	a->pivot = TRUE;
	pivot = a->data;
//	ft_printf("Pivot : %d\n", pivot);
	return (pivot);
}

void push_or_rotate(t_stack **a, t_stack **b, int pivot)
{
    int len;

    len = ft_llen(*a);
    while (len > 0)
    {
        if ((*a)->data >= pivot)
        {
            pb(a, b);
        }
        else
        {
            ra(a);
        }
        len--;
    }
}


void move_back_to_a(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_llen(*b);
	while (len > 0)
	{
		pa(a, b);
		len--;
	}
}

void dollar_sort(t_stack *a, t_stack *b)
{
	int pivot;

	pivot = set_pivot(a);
//	while (!stack_sorted(a))
//	{
		pll(a, b);
		ft_printf("Pivot : %d\n", pivot);
		push_or_rotate(&a, &b, pivot);
		move_back_to_a(&a, &b);
		pll(a, b);
//	}
}

void pll(t_stack *a, t_stack *b)
{
	ft_lprint(a);
	ft_lprint(b);
	ft_printf("\n");
}