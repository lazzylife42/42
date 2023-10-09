/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:32:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/09 17:25:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_bubble_sort(int arr[], int n)
{
	int	sorted;
	int	i;
	int	j;

	sorted = 0;
	i = 0;
	while (i < n - 1)
	{
		sorted = 1;
		j = 0;

		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				ft_swap(&arr[j], &arr[j + 1]);
				sorted = 0;
			}
			j++;
		}
		if (sorted)
			break ;
		i++;
	}
}

static void	ft_sort_stack_data(t_stack *a)
{
	int		i;
	int		*pos_to_sort;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	pos_to_sort = (int *)malloc(sizeof(int) * ft_llen(a));
	while (tmp != NULL)
	{
		pos_to_sort[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	ft_bubble_sort(pos_to_sort, ft_llen(a));
	tmp = a;
	i = 0;
	while (i < ft_llen(a))
	{
		while (tmp != NULL && tmp->data != pos_to_sort[i])
			tmp = tmp->next;
		if (tmp != NULL)
		{
			tmp->index = i + 1;
			tmp = a;
		}
		i++;
	}
	free(pos_to_sort);
}

t_stack	*ft_index_sort(t_stack *a)
{
	ft_sort_stack_data(a);
	return (a);
}