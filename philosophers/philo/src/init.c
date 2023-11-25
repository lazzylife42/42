/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:56:04 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/25 11:40:07 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void philo_init(t_philo *philo, int id, t_table *table)
{
	philo->id = id;
	philo->full = 0;
	philo->meals_count = 0;
	philo->last_meal_time = 0;
	philo->fork_left = &(table->forks[id]);
	philo->fork_right = &(table->forks[(id + 1) % table->philo_nbr]);
	philo->meal_limit_nbr = table->meal_limit_nbr;
    pthread_create(&(philo->thread_id), NULL, philosopher_thread_function(philo, table), philo);
}

// static void init_fork(t_fork *fork)
// {
// 	fork->fork_id = 0;
// 	pthread_mutex_init(&(fork->fork), NULL);
// }


void	init_simulation(int argc, char **argv, t_table *table)
{
	int				i;
	struct timeval	tv;
	
	table->philo_nbr = (long)ft_atoll(argv[1]);
	table->time_to_die = (long)ft_atoll(argv[2]);
	table->time_to_eat = (long)ft_atoll(argv[3]);
	table->time_to_sleep = (long)ft_atoll(argv[4]);
	if (argc == 6)
		table->meal_limit_nbr = (int)ft_atoll(argv[5]);
	else
		table->meal_limit_nbr = -1;
	gettimeofday(&tv, NULL);
	table->simulation_start = tv.tv_usec;
	table->simulation_end = FALSE;
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	i = 0;
	while (i < table->philo_nbr)
	{
		table->forks[i].fork_id = i;
		pthread_mutex_init(&(table->forks[i].fork), NULL);
		i++;
	}
	i = 0;
	while (i < table->philo_nbr)
	{
		philo_init(&(table->philos[i]), i, table);
		i++;
	}
}

