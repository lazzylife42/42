/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:14:21 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/28 22:07:13 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack **node)
{
	t_stack *last;
    t_stack *secondLast;
	
    if (*node == NULL || (*node)->next == NULL)
        return;

    last = *node;
    secondLast = NULL;
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }
    secondLast->next = NULL;
    last->next = *node;
    *node = last;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
