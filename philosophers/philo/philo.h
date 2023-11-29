/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:13:09 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/29 19:05:24 by smonte-e         ###   ########.fr       */
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
# include <errno.h>

/*	DEFINES			*/

# define TRUE		1
# define FALSE		0
# define MIN_TIME	6e4
# define DEBUG_MODE FALSE

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

/*	OPCODE MUTEX	 */

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}				t_opcode;

/*	CODEs for time	*/

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}				t_time_code;

/*	PHILO STATE		*/

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}				t_philo_status;

/*	TYPEDEF			*/

typedef 		pthread_mutex_t t_mtx;
typedef struct 	s_table	t_table;

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
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_table		*table;
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
	int			all_threads_ready;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
};

/*
////////////////	FONCTIONS		////////////////
*/

/*	UTILS				*/

void	    error_exit(const char *error);
long		gettime(t_time_code time_code);
void		precise_usleep(long usec, t_table *table);

/*	SYNC UTILS			*/

void		wait_all_threads(t_table *table);

/*	SAFE FONCTIONS		*/

void		*s_malloc(size_t bytes);
void		*s_mutex(t_mtx *mutex, t_opcode opcode);
void		*s_thread(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);

/*	INPUT CHECK			*/

void		parse_input(int argc, char **argv, t_table *table);

/*	INIT				*/

void		init_simulation(int argc, char **argv, t_table *table);
void		data_init(t_table *table);

/*	GETTERS AND SETTERS	*/

void	set_int(t_mtx *mutex, int *dest, int value);
void	set_long(t_mtx *mutex, long *dest, long value);
int		get_int(t_mtx *mutex, int *value);
long	get_long(t_mtx *mutex, long *value);
int		simulation_finished(t_table *table);

/*	THEAD FONCTIONS		*/

void		*philosopher_thread_function(void *arg);

/*	WRITE				*/

void		write_status(t_philo_status status, t_philo *philo, int debug);

/*	DINNER				*/

void		dinner_start(t_table *table);
void		*dinner_simulation(void *data);


#endif