/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:43:42 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/27 17:56:28 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	t_stack	*a;
//	t_stack	*b;

	i = 1;
	a = NULL;
//	b = NULL;
	if (argc == 1|| (argc == 2 && !argv[1][0]))
		return (1);
	else
		{
			error_check(argv);
			while (argv[i])
			{
				ft_lpush_back(&a, ft_atoi(argv[i]));
				i++;
			}
			ft_lprint(a);
		}
/*		
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
*/
}