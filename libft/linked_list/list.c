/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:16:25 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/12 01:37:07 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static Cell *create_cell(int data)
{
	Cell *cell = malloc(sizeof(cell));
	if (!cell)
		return NULL;
	cell->data = data;
	cell->next = NULL;
	return cell;
}

void	set_at(List *list, int data, int pos)
{
	int i;

	i = 0;
	if (is_emplty_list(list))
		printf("La liste est vide\n");
	while (i < pos)
	{
		i++;
		list = list->next;
	}
	list->data = data;
}

void	print_list(List *list)
{
	while (list)
	{
		printf("[%d] -> ", list->data);
		list = list->next;
	}
	printf("\n");
}

int		is_emplty_list(List *list)
{
	return list == NULL;
}

int		get_at(List *list, int pos)
{
	int i;

	i = 0;
	if (is_emplty_list(list))
	{
		printf("La liste est vide\n");
		return -1;
	}
	while (i < pos)
	{
		i++;
		list = list->next;
	}
	return list->data;
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

List	*empty_list(void)
{
	return NULL;
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
	if (is_emplty_list(list))
		return cell;
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
		cur =cur->next;
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
	if (is_emplty_list(list))
		return NULL;
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

List	*free_list(List *list)
{
	List *tmp;
	
	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return list;
}