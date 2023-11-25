/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:13:09 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/25 13:14:35 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*	INCLUDES		*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <limits.h>

/*	DEFINES			*/

# define TRUE	1
# define FALSE	0

// Define ANSI escape sequences for text color

# define RST	"\033[0m"    
# define RED	"\033[31m"      
# define G 		"\033[32m"      
# define Y		"\033[33m"
# define YL		"\033[1;33m"     
# define B		"\033[34m"      
# define M		"\033[35m"      
# define C		"\033[36m"      
# define W		"\033[37m"      


/*	TYPEDEF			*/

typedef 		pthread_mutex_t t_mtx;
/*typedef struct	s_table t_table;*/

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
	long		meal_limit_nbr;
	t_fork		*fork_left;
	t_fork		*fork_right;
	pthread_t	thread_id;
}				t_philo;

/*	STRUCT	TABLE	*/

typedef struct s_table
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
////////////////	FONCTIONS		////////////////
*/

/*	UTILS			*/

void	    error_exit(const char *error);
long long	ft_atoll(const char *str);

/*	INPUT CHECK		*/

void		check_input(int argc, char **argv);

/*	INIT			*/

void		init_simulation(int argc, char **argv, t_table *table);

/*	THEAD FONCTIONS	*/

void	*philosopher_thread_function(void *arg);

#endif