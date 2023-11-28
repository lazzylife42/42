/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:12:49 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/28 23:21:44 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	data_init(t_table *table)
{
	table->simulation_end = FALSE;
	table->philos = s_malloc(table->philo_nbr);
	
}