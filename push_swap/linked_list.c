/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:28:45 by sab               #+#    #+#             */
/*   Updated: 2023/10/10 13:44:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_lprint(t_stack *node)
{
	while (node != NULL)
	{
		ft_printf("[%d] -> ", node->data);
		node = node->next;
	}
	ft_printf("NULL\n");
}
*/
int	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

int	ft_llen(t_stack *node)
{
	int	res;

	res = 0;
	while (node != NULL)
	{
	res++;
	node = node->next;
	}
	return (res);
}

int	ft_lpush(t_stack **head, int new_data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (-1);
	new_node->data = new_data;
	new_node->next = *head;
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
	return (0);
}

int	ft_lpush_back(t_stack **head, int new_data)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (-1);
	new_node->data = new_data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (0);
}

int	ft_ldelete(t_stack **head, t_stack *del)
{
	if (*head == NULL || del == NULL)
		return (-1);
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return (0);
}
