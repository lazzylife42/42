/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ghetto_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/20 14:03:47 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ghetto_sort(List **a, List **b)
{
	pb(a, b);
	while (len_list(*a) >= 3)
	{
		if ((*a)->data > (*b)->data)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
	}
	tiny_sort(a);
	while ((*b)->next != NULL)
			pa(a, b);
	while (!list_sorted(*a))
			rra(a);
	print_list(*a);
	print_list(*b);
}