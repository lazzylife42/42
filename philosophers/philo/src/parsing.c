/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:19:51 by sab               #+#    #+#             */
/*   Updated: 2023/12/01 11:11:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	long ft_atol(const char *str)
{
	int		i;
	int		signe;
	long	cache;

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

static	void	check_input(int argc, char **argv)
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
				error_exit("One of your inputs is not a valid number\n"
					G"Try positive numbers only."RST);
			j++;
		}
		if (ft_atol(argv[i]) > INT_MAX)
			error_exit("Some input(s) may be too big\n"
				G"Try only "B"int"G"."RST);
		i++;
	}
}

void	parse_input(int argc, char **argv, t_table *table)
{
	check_input(argc, argv);
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < MIN_TIME
		|| table->time_to_eat < MIN_TIME
		|| table->time_to_sleep < MIN_TIME)
		error_exit("Try more than 60ms.");
	if (argc == 6)
		table->meal_limit_nbr = ft_atol(argv[5]);
	else
		table->meal_limit_nbr = -1;
}