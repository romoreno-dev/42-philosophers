/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:50:15 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:50:15 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	ft_is_philo_dead(t_philo *philo)
{
	int		result;
	long	last_eat_time;

	sem_wait(philo->last_eat_variable);
	last_eat_time = philo->last_eat_time;
	sem_post(philo->last_eat_variable);
	if ((ft_running_time(philo->table) - last_eat_time)
		> philo->table->time_to_die)
	{
		result = 1;
		ft_write(DIED, philo);
	}
	else
	{
		result = 0;
	}
	return (result);
}

int	ft_must_end_simulation(t_philo *philo)
{
	int	philo_full;
	int	i;

	philo_full = 1;
	if (philo != NULL)
	{
		if (ft_is_philo_dead(philo))
		{
			i = 0;
			while (i < philo->table->philo_numbers)
				sem_post(philo->table->finished);
			return (1);
		}
		if (philo->table->limit_eat_nbr == -1
			|| philo->eat_counter < philo->table->limit_eat_nbr)
			philo_full = 0;
		if (philo_full == 1)
			sem_post(philo->table->finished);
	}
	return (philo_full);
}

void	ft_init_main_monitor(t_table *table)
{
	int	i;

	i = 0;
	ft_protected_thread(table->monitor, ft_main_monitor_routine, table, CREATE);
	ft_protected_thread(table->monitor,
		NULL, NULL, DETACH);
	while (i < table->philo_numbers)
	{
		waitpid(-1, 0, 0);
		i++;
	}
}

void	*ft_main_monitor_routine(void *param)
{
	t_table	*table;
	int		i;

	table = (t_table *)param;
	i = 0;
	while (i < table->philo_numbers)
	{
		sem_wait(table->finished);
		i++;
	}
	ft_kill_all_philos(table);
	return (NULL);
}

void	*ft_philo_monitor_routine(void *param)
{
	t_philo	*philo;

	philo = param;
	while (1)
	{
		if (ft_must_end_simulation(philo))
		{
			sem_wait(philo->can_eat);
			break ;
		}
	}
	return (NULL);
}
