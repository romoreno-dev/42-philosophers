/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:51:05 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:51:05 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// ******************************* LIBRARIES ***********************************
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <limits.h>

// ******************************* CODES **************************************
# define SEM_FORKS "/forks"
# define SEMAPHORE_WRITER "/writer"
# define SEMAPHORE_FINISHED "/finished"
# define SEM_CAN_EAT "/caneat"
# define SEM_LAST_EAT "/lasteatvariable"

// ******************************* COLORS **************************************
# define PRINT		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"

// ******************************* MESSAGES ************************************
# define ERROR_MALLOC "Error with memory allocation while executing malloc"
# define ERROR_THREAD "Error with thread management"
# define ERROR_MUTEX "Error with mutex management"
# define ERROR_GET_TIME "Error executing gettimeofday function"
# define ERROR_MISSING_ARGS_INPUT "Missing args in input"
# define ERROR_INVALID_INPUT "Invalid input"
# define ERROR_MISSING_INPUT "Missing input"
# define ERROR_INPUT_NEGATIVE "Only positive values greater than 0 is allowed"
# define ERROR_INPUT_TOO_BIG "Too big number was introduced"
# define ERROR_STRING_INPUT "Must introduce numbers"
# define WARNING_MANY_PHILOS "More than 200 philos is not recommended. Unexp."
# define WARNING_LOW_TIME "Less than 60 ms is not recommended. Unexp. behaviour"

// ******************************* ENUMS ***************************************
typedef enum e_philo_status
{
	EAT,
	SLEEP,
	THINK,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

typedef enum e_mutex_option
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
}	t_mutex_option;

typedef enum e_thread_option
{
	CREATE,
	JOIN,
	DETACH
}	t_thread_option;

typedef enum e_time
{
	MICROSECONDS,
	MILLISECONDS
}	t_time;

// ******************************* STRUCTS *************************************
typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	long			eat_counter;
	t_table			*table;
	long			last_eat_time;
	pthread_t		*check_dead_th;
	sem_t			*can_eat;
	sem_t			*last_eat_variable;
}	t_philo;

typedef struct s_table
{
	long			philo_numbers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			limit_eat_nbr;
	long			start_time;
	int				simulation_finished;
	t_philo			**philos;
	pthread_t		*monitor;
	sem_t			*forks;
	sem_t			*writer;
	sem_t			*finished;
	pid_t			*pid;
}	t_table;

// ******************************* FUNCTIONS ***********************************

long	ft_atol(char *str);
int		ft_is_digit(int c);
int		ft_is_space(int c);
char	*ft_check_input(char *str);
void	ft_exit_error(const char *error);
void	ft_process_input(t_table *table, char **argv);
void	*ft_protected_malloc(size_t bytes);
void	ft_protected_mutex(pthread_mutex_t *mutex, t_mutex_option option);
void	ft_protected_thread(pthread_t *thread, void *(*routine)(void *),
			void *data, t_thread_option option);
void	ft_init_table(t_table *table);
void	ft_init_philos(t_table *table);
void	ft_init_forks(t_table *table);
long	ft_current_ms_time(void);
long	ft_running_time(t_table *table);
void	ft_write(t_philo_status status, t_philo *philo);
void	ft_start_philos(t_table *table);
void	ft_init_main_monitor(t_table *table);
void	*ft_philo_monitor_routine(void *param);
void	*ft_main_monitor_routine(void *param);
void	ft_philo_process_routine(void *param);
void	ft_kill_all_philos(t_table *table);
int		ft_must_end_simulation(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_clean(t_table *table);
void	ft_join(t_table *table);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
#endif
