/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:45:41 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/24 15:12:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void check_input(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				error_exit("One of your inputs is not a valid number\n"G"Try numbers only."RST);
			j++;
		}
		i++;
	}
	if (ft_atoll(argv[1]) < 1 || ft_atoll(argv[1]) > LONG_MAX)
		error_exit("Number of philosopher(s) too low or to big\n"G"Try one or more (But less than LONG_MAX)."RST);
	if (ft_atoll(argv[2]) < 1 || ft_atoll(argv[2]) > LONG_MAX)
		error_exit("Simulation time too low or to big\n"G"Try 1ms or more (But less than LONG_MAX)."RST);
	if (ft_atoll(argv[3]) < 1 || ft_atoll(argv[2]) > LONG_MAX)
		error_exit("Eat time too low or to big\n"G"Try 1ms or more (But less than LONG_MAX)."RST);
	if (ft_atoll(argv[4]) < 1 || ft_atoll(argv[3]) > LONG_MAX)
		error_exit("Sleep time too low or to big\n"G"Try 1ms or more (But less than LONG_MAX)."RST);
	if (argc == 6)
	{
		if (ft_atoll(argv[5]) < 1 || ft_atoll(argv[5]) > INT_MAX)
			error_exit("Each philosopher must eat at least 1 time\n"G"Try one or more (But less than INT_MAX)."RST);
	}
}
