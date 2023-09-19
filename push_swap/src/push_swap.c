/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:54:54 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/15 02:11:52 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	// print_list(a);
	// ra(&a);
	// print_list(a);
	// rb(&a);
	// print_list(a);
	// sa(&a);
	// print_list(a);
	// sb(&a);
	// print_list(a);
	// ss(&a, &a);
	// print_list(a);
	// rr(&a, &a);
	// print_list(a);
	// rra(&a);
	// print_list(a);
	// rrb(&a);
	// print_list(a);
	// rrr(&a, &a);
	// print_list(a);
	// print_list(b);
	// pa(&a, &b);
	// print_list(a);
	// print_list(b);
	// pb(&b, &a);
	// print_list(a);
	// print_list(b);

	// if (!list_sorted(a))
	// 	printf("Non!");
	// else
	// 	print_list(a);
	

}
