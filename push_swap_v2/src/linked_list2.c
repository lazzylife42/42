/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:39:15 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/04 14:58:00 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_data_at(t_stack *node, int data, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		i++;
		node = node->next;
	}
	node->data = data;
}

void	set_pivot_at(t_stack *node, int pos)
{
	int	i;

	i = 0;
	while (i < ft_llen(node))
	{
		node->pivot = FALSE;
		if (i == pos)
		{
			node->pivot = TRUE;
			i++;
			node = node->next;
		}
		i++;
		node = node->next;
	}
	node->pivot = TRUE;
}

void	set_p_first(t_stack *node, int pos)
{
	int	i;

	i = 0;
	while (i < ft_llen(node))
	{
		node->p_first = FALSE;
		if (i == pos)
		{
			node->p_first = TRUE;
			i++;
			node = node->next;
		}
		i++;
		node = node->next;
	}
	node->p_first = TRUE;
}

void	set_p_last(t_stack *node, int pos)
{
	int	i;

	i = 0;
	while (i < ft_llen(node))
	{
		node->p_last = FALSE;
		if (i == pos)
		{
			node->p_last = TRUE;
			i++;
			node = node->next;
		}
		i++;
		node = node->next;
	}
	node->p_last = TRUE;
}