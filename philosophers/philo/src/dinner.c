/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:02 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/29 19:47:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	void	eat(t_philo *philo)
{
	s_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	s_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	philo->meals_count++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->meal_limit_nbr > 0
		&& philo->meals_count == philo->table->meal_limit_nbr)
		set_int(&philo->philo_mutex, &philo->full, TRUE);
	s_mutex(&philo->first_fork->fork, UNLOCK);
	s_mutex(&philo->second_fork->fork, UNLOCK);
}

static	void	think(t_philo *philo)
{
	write_status(THINKING, philo, DEBUG_MODE);
}

void	dinner_start(t_table *table)
{
	int i;

	i = -1;
	if (table->meal_limit_nbr == 0)
		return ;
	else if (table->meal_limit_nbr == 1)
		;
	else
		while (++i < table->philo_nbr)
			s_thread(&table->philos[i].thread_id, &dinner_simulation, 
				&table->philos[i], CREATE);
	table->simulation_start = gettime(MILLISECOND);
	set_int(&table->table_mutex, &table->all_threads_ready, TRUE);
	i = -1;
	while (++i < table->philo_nbr)
		s_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	
}

void	*dinner_simulation(void *data)
{
	t_philo *philo;
	philo = (t_philo *)data;
	
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	
	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->time_to_sleep, philo->table);
	//	sleep(philo);
		think(philo);
	}
	return (NULL);
}