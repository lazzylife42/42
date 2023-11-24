/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:45:41 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/24 12:57:44 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	cache;

	i = 0;
	signe = 1;
	cache = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		cache = cache * 10 + (str[i] - 48);
		i++;
	}	
	return (signe * cache);
}

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
	if (ft_atoi(argv[1]) < 1)
		error_exit("Number of philosopher(s) too low\n"G"Try one or more."RST);
	if (ft_atoi(argv[2]) < 1)
		error_exit("Simulation time too low\n"G"Try 1ms or more."RST);
	if (ft_atoi(argv[3]) < 1)
		error_exit("Eat time too low\n"G"Try 1ms or more."RST);
	if (ft_atoi(argv[4]) < 1)
		error_exit("Sleep time too low\n"G"Try 1ms or more."RST);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 1)
			error_exit("Each philosopher must eat at least 1 time\n"G"Try one or more."RST);
	}
}
