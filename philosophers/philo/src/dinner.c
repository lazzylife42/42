/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:02 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/29 12:01:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
			s_thread(&table->philos[i].thread_id, dinner_simulation, 
				&table->philos[i], CREATE);
	table->start_simulation = gettime(MILLISECOND);
	set_int(&table->table_mutex, &table->all_threads_ready, TRUE);
	i = -1;
	while (++i < table->philo_nbr)
	{
		s_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	}
}

void	*dinner_simulation(void *data)
{
	t_philo *philo;
	philo = (t_philo)data;
	
	wait_all_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break ;
		//1:17:53
	}
}