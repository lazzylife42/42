/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:42:13 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/21 20:25:58 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(List *list)
{
	int smallest;
	List *tmp;
	
	tmp = list;
	smallest = list->data;
	while (list->next != NULL)
	{
		if (smallest > list->data)
			smallest = list->data;
		list = list->next;
	}
//	printf("Smallest -> [%i]\n", smallest);
	return (find_pos_w_data(tmp, smallest));
}

int	find_largest(List *list)
{
	int largest;
	List *tmp;
	
	tmp = list;
	largest = list->data;
	while (list->next != NULL)
	{
		if (largest < list->data)
			largest = list->data;
		list = list->next;
	}
//	printf("Largest  -> [%i]\n", largest);
	return (find_pos_w_data(tmp, largest));
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
//	printf("Pos -> %i\n", pos);
	return (pos);
}

int price_sx(int pos)
{
	if (pos != 1)
		pos = INT_MAX;
//	printf("Price : $%d\n", pos);
	return (pos);
}

int price_rx(int pos)
{
//	printf("Price : $%d\n", pos);
	return (pos);
}

int price_rrx(List *list, int pos)
{
	int price;

	price = 0;
	pos = len_list(list) - pos;
	while (pos > 0)
	{
		pos--;
		price++;
	}
//	printf("Price : $%d\n", price);
	return (price);
}

int	move_sx_rx_rrx(List *list, int pos)
{
//	printf("POS = %d | %d\n", pos, price_rrx(list, pos));
	if (pos == 1)
		return (SX);
	if (pos < price_rrx(list, pos))
		return (RX);
	return (RRX);
}

int	move_small_or_large(List *list, int smallest, int largest)
{
	int	price_small;
	int price_larg;

	price_small = move_sx_rx_rrx(list, smallest);
	price_larg = move_sx_rx_rrx(list, largest);
	
	if (price_small == SX)
		price_small = price_sx(smallest);
	else if (price_small == RX)
		price_small = price_rx(smallest);
	else if (price_small == RRX)
		price_small = price_rrx(list, smallest);
			
	if (price_larg == SX)
		price_larg = price_sx(largest);
	else if (price_larg == RX)
		price_larg = price_rx(largest);
	else if (price_larg == RRX)
		price_larg = price_rrx(list, largest);
//	printf("small[%d] large[%d]\n", price_small, price_larg);
	if (price_small < price_larg)
		return (SMALLEST);
	return (LARGEST);
}
