/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:36:03 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/29 18:06:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	dollar_sort(t_stack *a, t_stack *b)
{
	pb(&a, &b);
	pb(&a, &b);
	if ((b)->data < (b)->next->data)
		rb(&b);
	while (!stack_sorted(a))
	{
		push_b_top_to_low(&a, &b);
	}
	ra(&a);
	while (!stack_reverse_sorted(a))
	{
		if (a->data < b->data)
			push_a_top_to_low(&a, &b);
		b = b->next;
	}		
}

int	stack_reverse_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

void push_b_top_to_low(t_stack **a, t_stack **b)
{
	t_stack *current_a = *a;
	t_stack *current_b = *b;

	refresh_price(current_a);
	refresh_next(current_a);
	while (current_a != NULL || ft_llen(current_a) > 3)
	{
		if (current_a->next_to_move == TRUE)
		{
			if (current_a->data > current_b->data)
			{
				pb(a, b);
				refresh_price(current_a);
				refresh_next(current_a);				
			}
			else if (current_a->data < current_b->data)
			{
				reverse_sort_b(b);
				pb(a, b);
				refresh_price(current_a);
				refresh_next(current_a);
				reverse_sort_b(b);
			}
		}
		current_a = current_a->next;
	}
}

void push_a_top_to_low(t_stack **a, t_stack **b) {
    t_stack *current_a = *a;
    t_stack *current_b = *b;

    refresh_price(current_b);
    refresh_next(current_b);

    while (current_b != NULL || ft_llen(current_b) > 3) {
        if (current_b->next_to_move == TRUE) {
            if (current_b->data > current_a->data)
                pa(a, b);
            else if (current_b->data < current_a->data) {
                pa(a, b);
                while (find_lowest(current_a) != current_a)
                    ra(a);
            }
        }

        current_b = current_b->next;
        refresh_price(current_b);
        refresh_next(current_b);
    }
}

void	reverse_sort_b(t_stack **b)
{
	int pos;

	pos = 0;
	while (!stack_sorted(*b))
	{
		if (pos < ft_llen(*b) + 1 / 2)
		{
				rb(b);		
		}
		else if (pos > ft_llen(*b) + 1 / 2)
		{
				rrb(b);
		}
		(*b) = (*b)->next;
		pos++;
	}
}	