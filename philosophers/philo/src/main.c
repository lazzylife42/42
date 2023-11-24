/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:12:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/24 16:20:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	t_table *table;
	
	if (argc == 5 || argc == 6)
	{
		check_input(argc, argv);
		table = malloc(sizeof(t_table));
		if (!table)
			error_exit("Malloc error");
		init_simulation(argc, argv, &table);
	}
	else
	{
		error_exit("Bad input\n"G"Try \"./philo "B"long long long long"G" ["B"int"G"]\""RST);
	}
	return (EXIT_SUCCESS);
}