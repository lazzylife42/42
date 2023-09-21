/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:54:54 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/21 22:05:45 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	List	*a;
	List	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = array_to_llist(argv, a, argc);
	if (!list_sorted(a))
	{
		if (len_list(a) == 2)
			sa(&a);
		else if (len_list(a) == 3)
			tiny_sort(&a);
		else
		{
			print_list(a);
			print_list(b);
			pb(&a, &b);
			pb(&a, &b);
			b_boy(a);
			while (len_list(a) > 3)
			{
				ghetto_sort(&a, &b);
				if (a->data > b->data)
					pb(&a, &b);
				else if (a->data < b->data)
				{
					pb(&a, &b);
					rb(&b);
				}
			}
			tiny_sort(&a);
			print_list(a);
			print_list(b);
			while(b->next != NULL)
				pa(&a, &b);
			pa(&a, &b);
			//while (!list_sorted(a))
			//	ra(&a);
			print_list(a);
			print_list(b);
		}
	}

}
