/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ghetto_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/22 03:10:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ghetto_sort(List **a, List **b)
{
	print_list(*a);
	print_list(*b);
	printf("====================\n");
	play_maker(a);
	pb(a, b);
	printf("====================\n");
	print_list(*a);
	print_list(*b);

	
}

int	n_val(List *list, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		list = list->next;
		i++;
	}
	return(list->data);
}
void	b_boy(List **b)
{
	while ((*b)->data != find_highest(*b)->data)
		rb(b);
}

void play_maker(List **a)
{
    int small_large;
    int sx_rx_rrx;
    int data;

    data = 0;
    small_large = move_small_or_large(*a, find_smallest(*a), find_largest(*a));
    if (small_large == SMALLEST)
    {
        sx_rx_rrx = move_sx_rx_rrx(*a, find_smallest(*a));
        data = n_val(*a, find_smallest(*a));
    }
    else if (small_large == LARGEST)
    {
        sx_rx_rrx = move_sx_rx_rrx(*a, find_largest(*a));
        data = n_val(*a, find_largest(*a));
    }
    while (data != (*a)->data)
    {
        if (sx_rx_rrx == SX)
            sa(a);
        else if (sx_rx_rrx == RX)
            ra(a);
        else
            rra(a);
    }
}

