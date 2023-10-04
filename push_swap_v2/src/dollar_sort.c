/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:36:03 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/02 17:56:47 by smonte-e         ###   ########.fr       */
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

void push_or_rotate_a(t_stack **a, t_stack **b, int pivot)
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

void push_or_rotate_b(t_stack **a, t_stack **b, int pivot)
{
    int len;

    len = ft_llen(*a);
    while (len > 0)
    {
        if ((*b)->data >= pivot)
        {
            pa(a, b);
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

void move_back_to_b(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_llen(*a);
	while (len > 0)
	{
		pb(a, b);
		len--;
	}
}

void dollar_sort(t_stack *a, t_stack *b)
{
	int pivot;
	int passe;
	
	passe = 0;
	pivot = set_pivot(a);
	while (passe < 10)
	{
		push_or_rotate_a(&a, &b, pivot);
		pivot = set_pivot(b);
		push_or_rotate_b(&a, &b, pivot);
		move_back_to_a(&a, &b);
		pivot /= set_pivot(a);
		passe++;
	}
}

void pll(t_stack *a, t_stack *b)
{
	ft_lprint(a);
	ft_lprint(b);
	ft_printf("\n");
}