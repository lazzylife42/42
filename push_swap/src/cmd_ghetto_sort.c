/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ghetto_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/20 18:45:53 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ghetto_sort(List **a, List **b)
{
	print_list(*a);
	print_list(*b);
	printf("====================\n");
	pb(a, b);
	pb(a, b);
}

int	find_smallest(List *list)
{
	int smallest;
	
	smallest = list->data;
	while (list->next != NULL)
	{
		if (smallest > list->data)
			smallest = list->data;
		list = list->next;
	}
	printf("Smallest -> [%i]\n", smallest);
	return (smallest);
}

int	find_largest(List *list)
{
	int largest;
	
	largest = list->data;
	while (list->next != NULL)
	{
		if (largest < list->data)
			largest = list->data;
		list = list->next;
	}
	printf("Largest  -> [%i]\n", largest);
	return (largest);
}