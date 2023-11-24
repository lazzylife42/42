/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:12:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/24 14:32:13 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	(void)argv;
//	t_table table;

	if (argc == 5 || argc == 6)
	{
		check_input(argc, argv);
		return 1;
	}
	else
	{
		error_exit("Bad input\n"G"Try \"./philo "B"long long long long"G" ["B"int"G"]\""RST);
	}
	return (0);
}