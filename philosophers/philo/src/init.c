/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:04 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/24 16:15:53 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// static	void	init_philo(t_philo *philo);

// static	void	init_fork(t_fork *fork);


void	init_simulation(int argc, char **argv, t_table *table)
{
	struct timeval	tv;
	
	table->philo_nbr = (int)ft_atoll(argv[1]);
	table->time_to_die = (int)ft_atoll(argv[2]);
	table->time_to_eat = (int)ft_atoll(argv[3]);
	table->time_to_sleep = (int)ft_atoll(argv[4]);
	if (argc == 6)
		table->meal_limit_nbr = (int)ft_atoll(argv[5]);
	else
		table->meal_limit_nbr = -1;
	gettimeofday(&tv, NULL);
	table->simulation_start = (long)tv;
}

