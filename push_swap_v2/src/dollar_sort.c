/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:36:03 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/02 03:14:05 by smonte-e         ###   ########.fr       */
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

t_stack	push_or_rotate(t_stack *a, t_stack *b, int pivot)
{
	t_stack *tmp;
	
	tmp = a;
    while (a != NULL)
    {
        if ((a)->data > pivot)
        {
            pb(&a, &b);
        }
        else
        {
            ra(&a);
        }
		a = (a)->next;
    }
	return (*tmp);
}

void move_back_to_a(t_stack *a, t_stack *b)
{
	while ((b) != NULL)
	{
		pa(&a, &b);
		(b) = (b)->next;
	}
}

void dollar_sort(t_stack *a, t_stack *b)
{
	int pivot;
	
	while (!stack_sorted(a))
	{
		pivot = set_pivot(a);
		ft_printf("Pivot : %d\n", pivot);
		*a = push_or_rotate(a, b, pivot);
		ft_lprint(a);
		ft_lprint(b);
//		move_back_to_a(a, b);
	}
}