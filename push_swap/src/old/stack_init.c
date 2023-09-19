/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:08:52 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/13 00:10:46 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack_node **a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_free(a, argv);
		if (error_repetition(*a, (int)number))
			error_free(a, argv);
		append_node(a, (int)number);
		++i;
	}
	// if (flag_argc_2)
	// 	free_matrix(argv);
}