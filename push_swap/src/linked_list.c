/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:24:08 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/20 12:31:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static Cell *create_cell(int data)
{
	Cell *cell = malloc(sizeof(Cell));
	if (!cell)
		return NULL;
	cell->data = data;
	cell->next = NULL;
	return cell;
}

void	print_list(List *list)
{
	while (list)
	{
		printf("[%d] -> ", list->data);
		list = list->next;
	}
	printf("NULL\n");
}

long	len_list(List *list)
{
	long len;
	
	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return len;
}

List	*add_at(List *list, int data, int pos)
{
	int i;
	List *prec;
	List *cur;
	Cell *cell;
	
	prec = list;
	cur = list;
	cell = create_cell(data);
	if (pos == 0)
	{
		cell->next = list;
		return cell;
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return list;
}

List	*free_at(List *list, int pos)
{
	int i;
	List *prec;
	List *cur;
	
	prec = list;
	cur = list;
	if (pos == 0)
	{
		list =list->next;
		free(cur);
		return list;
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur =cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return list;
}

List	*array_to_llist(char **array, List *list, int argc)
{
	int i;

	i = 0;
	list = NULL;
	while (array[i])
	{
		list = add_at(list, ft_atol(array[i]), i);
		i++;
	}
	if (argc > 2)
		list = free_at(list, 0);
	return list;
}

List	*free_list(List *list)
{
	List	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (list);
}