/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:30:45 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/28 12:32:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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