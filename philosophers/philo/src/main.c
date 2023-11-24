/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:12:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/24 12:21:52 by smonte-e         ###   ########.fr       */
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
		error_exit("Bad input\n"G"Try \"./philo 5 800 200 200 [5]\""RST);
	}
	return (0);
}