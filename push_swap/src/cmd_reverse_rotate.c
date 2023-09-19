/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:14:21 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/15 01:43:46 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(List **list)
{
	List *last;
    List *secondLast;
	
    if (*list == NULL || (*list)->next == NULL)
        return;

    last = *list;
    secondLast = NULL;
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }
    secondLast->next = NULL;
    last->next = *list;
    *list = last;
}

void rra(List **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(List **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(List **a, List **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
