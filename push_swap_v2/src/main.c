/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:43:42 by smonte-e          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/28 23:03:14 by smonte-e         ###   ########.fr       */
=======
/*   Updated: 2023/09/28 22:04:05 by smonte-e         ###   ########.fr       */
>>>>>>> 430902aa5c07740e74fae2eb8978a230e8102f3f
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
<<<<<<< HEAD
		return (1);		
	stack_init(a, argv);	
=======
		return (1);
	else
		{
			stack_init(a, b, argv);
		}
/*		
>>>>>>> 430902aa5c07740e74fae2eb8978a230e8102f3f
	if (!stack_sorted(a))
	{
		if (ft_llen(a) == 2)
			sa(&a);
		else if (ft_llen(a) == 3)
			tiny_sort(&a);
		else
			dollar_sort(a, b);
	}
	free_stack(&a);
	free_stack(&b);
}