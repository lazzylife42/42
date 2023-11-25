/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:48:09 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/25 13:16:41 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philosopher_thread_function(void *arg)
{
	t_philo *philo = (t_philo *)arg;

//	while (TRUE)
//	{
		printf(Y"Philosopher %d is thinking\n"RST, philo->id);
		pthread_mutex_lock(&(philo->fork_left->fork));
		printf(B"Philosopher %d took left fork\n"RST, philo->id);
		pthread_mutex_lock(&(philo->fork_right->fork));
		printf(C"Philosopher %d took right fork\n"RST, philo->id);
		printf(YL"Philosopher %d is eating\n"RST, philo->id);
		pthread_mutex_unlock(&(philo->fork_left->fork));
		printf(B"Philosopher %d released left fork\n"RST, philo->id);
		pthread_mutex_unlock(&(philo->fork_right->fork));
		printf(C"Philosopher %d released right fork\n"RST, philo->id);
		printf(M"Philosopher %d is sleeping\n"RST, philo->id);
//		if (philo->meal_limit_nbr != -1 && philo->meals_count >= philo->meal_limit_nbr)
//			break;
//	}
	pthread_exit(NULL);
}
