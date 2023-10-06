/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:43:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/06 20:57:18 by smonte-e         ###   ########.fr       */
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
	if (argc == 1|| (argc == 2 && !argv[1][0]))
		return (1);		
	stack_init(&a, argv);
	len = ft_llen(a);
	if (!stack_sorted(a))
	{
		if (len == 2)
			sa(&a);
		else if (len == 3)
			tiny_sort(&a);
		else if (len == 3 || len == 4 || len == 5)
			tiny_sort_5(&a, &b);
		else
		{
			update_index(a);
			a = index_sort(a);
			radix(&a, &b);
		}
	}
	free_stack(&b);
	free_stack(&a);
}