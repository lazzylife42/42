/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:13:52 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/15 01:23:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void rotate(List **list)
{
	List *last;

	last = *list;
    if (*list == NULL || (*list)->next == NULL) 
        return;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = *list;
    *list = (*list)->next;
    last->next->next = NULL;
}

void ra(List **a) {
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(List **b) {
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(List **a, List **b) {
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
