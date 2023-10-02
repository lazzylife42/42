/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:43:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/02 02:26:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1|| (argc == 2 && !argv[1][0]))
		return (1);		
	stack_init(&a, argv);
	if (!stack_sorted(a))
	{
		if (ft_llen(a) == 2)
			sa(&a);
		else if (ft_llen(a) == 3)
			tiny_sort(&a);
		else
		{
			dollar_sort(a, b);
			free_stack(&b);
		}	
	}
	free_stack(&a);
}