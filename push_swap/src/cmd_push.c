/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:13:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/15 01:57:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void push(List **a, List **b)
{
	List *top_b;
	
    if (*b == NULL)
        return;
    top_b = *b;
    *b = (*b)->next;
    top_b->next = *a;
    *a = top_b;
}

void pa(List **a, List **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void pb(List **a, List **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}
