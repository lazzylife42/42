/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:43:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/09 22:12:34 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_init(&a, argv);
	len = ft_llen(a);
	if (!stack_sorted(a) && len >= 5)
		tiny_sort(&a, &b);
	else if (!stack_sorted(a))
	{
		update_index(a);
		a = index_sort(a);
		radix(&a, &b);
		free_stack(&b);
		free_stack(&a);
	}
}
