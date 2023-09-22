/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ghetto_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/22 15:30:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ghetto_sort(List **a, List **b)
{

	slave_maker(a, b, play_maker(a));
	

	/*	INIT STACK B TOP TO LOW	*/

	/*	PUSH DANS B ET SORT B TOP TO LOW UNTIL len(STACK_A) == 3 */

	/*	B SORTED TOP TO LOW	*/

	
	
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

char *play_maker(List **a)
{
	int small_large;
	int sx_rx_rrx;
	int data;
	int i;
	char *instructions;
	
	instructions = (char *)malloc(sizeof(char) * (len_list(*a)) + 1);

	i = 0;
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
		{
			instructions[i] = SX;
			i++;
			//sa(a);
		}
		else if (sx_rx_rrx == RX)
		{
			instructions[i] = RX;
			i++;
			//ra(a);
		}
		else
		{
			instructions[i] = RRX;
			i++;
			//rra(a);
		}
		instructions[i] = '\0';
	}
	return (instructions);
}

void	slave_maker(List **a, List **b, char *instructions)
{
	int i = 0;
	print_list(*a);
	print_list(*b);
	printf("INSTRUCTIONS :");
	while (instructions)
	{
		if (instructions[i] == SX)
			printf("[SX]");
		else if (instructions[i] == RX)
			printf("[RX]");
		else if (instructions[i] == RRX)
			printf("[RX]");
		i++;
	}
	printf("\n");	
}