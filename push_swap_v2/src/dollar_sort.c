/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:36:03 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/04 12:28:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"


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
	pivot = 0;
	while (passe < 5)
	{
		push_or_rotate_a(&a, &b, pivot(a));
		push_or_rotate_b(&a, &b, pivot(b));
		move_back_to_a(&a, &b);
		passe++;
	}
}

void pll(t_stack *a, t_stack *b)
{
	ft_lprint(a);
	ft_lprint(b);
	ft_printf("\n");
}