/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:10:14 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/15 01:23:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc split.c push_swap_utils.c linked_list.c push_swap.c cmd_swap.c push_swap.h -Wall -Wextra

#include "push_swap.h"

static void swap(List **list)
{
	int tmp;
	
    if (*list == NULL || (*list)->next == NULL)
        return;
    tmp = (*list)->data;
    (*list)->data = (*list)->next->data;
    (*list)->next->data = tmp;
}

void sa(List **a) {
    swap(a);
    write(1, "sa\n", 3);
}

void sb(List **b) {
    swap(b);
    write(1, "sb\n", 3);
}

void ss(List **a, List **b) {
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
