/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:22:55 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/29 22:38:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	wait_all_threads(t_table *table)
{
    while (!get_int(&table->table_mutex, &table->all_threads_ready))
		;
}

void	increase_long(t_mtx *mutex, long *value)
{
	s_mutex(mutex, LOCK);
	(*value)++;
	s_mutex(mutex, UNLOCK);
}

int	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr)
{
	int	ret;
	
	ret = FALSE;
	s_mutex(mutex, LOCK);	
	if (*threads == philo_nbr)
		ret = TRUE;
	s_mutex(mutex, UNLOCK);
	return (ret);
}
