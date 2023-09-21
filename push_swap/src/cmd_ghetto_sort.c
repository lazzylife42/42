/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ghetto_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/21 00:02:36 by smonte-e         ###   ########.fr       */
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

int	find_pos_w_data(List *list, int data)
{
	int	pos;

	pos = 0;
	if (list->data == data)
		return (0);
	while (list->data != data)
	{
		pos++;
		list = list->next; 
	}
	printf("Pos -> %i\n", pos);
	return (pos);
}

int	price_to_top(List *list, int pos)
{
	int	price;

	price = 0;
	if ((len_list(list) / 2) < pos)
	{
		pos = len_list(list)/2 - pos;
		while (pos > 0)
		{
			price++;
			pos--;
		}
	}
	else
	{
		while (pos < 0)
		{
			price++;
			pos--;
		}
	}
	printf("Price to top -> $%i\n", price);
	return (price);
}

/*
void	find_next_move(List *a, List *b)
{
	int smallest;
	int	cost_largest;
	int	largest;
	int	cost_smallest;

	smallest = find_smallest(a);
	largest = find_largest(a);
	while ()	
}
*/
