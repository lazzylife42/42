/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:13:09 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/23 13:41:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*	INCLUDES		*/

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include "libft/libft.h"

/*	DEFINES			*/

# define TRUE	1
# define FALSE	0

// Define ANSI escape sequences for text color

# define RST	"\033[0m"    
# define RED	"\033[31m"      
# define G 		"\033[32m"      
# define Y		"\033[33m"      
# define B		"\033[34m"      
# define M		"\033[35m"      
# define C		"\033[36m"      
# define W		"\033[37m"      


/*	TYPEDEF			*/

typedef 		pthread_mutex_t t_mtx;
typedef struct	s_table t_tables;

/*	STRUCT	FORK	*/

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;

/*	STRUCT	PHILO	*/

typedef struct s_philo
{
	int			id;
	int			full;
	long		meals_count;
	long		last_meal_time;
	t_fork		*fork_left;
	t_fork		*fork_right;
	pthread_t	thread_id;
}				t_philo;

/*	STRUCT	TABLE	*/

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		meal_limit_nbr;
	long		simulation_start;
	int			simulation_end;
	t_fork		*forks;
	t_philo		*philos;
}				t_table;

/*
////	FONCTIONS	////
*/

/*	ERROR		*/

void    error_exit(const char *error);

#endif