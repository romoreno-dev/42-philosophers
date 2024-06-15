/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:33:29 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/23 18:33:29 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_is_philo_dead(t_philo *philo)
{
	int	result;

	ft_protected_mutex(&philo->philo_mutex, LOCK);
	if (ft_running_time(philo->table) - philo->last_eat_time
		> philo->table->time_to_die)
	{
		ft_protected_mutex(&philo->table->table_mutex, LOCK);
		philo->table->simulation_finished = 1;
		result = 1;
		ft_protected_mutex(&philo->table->table_mutex, UNLOCK);
		ft_write(DIED, philo);
	}
	else
	{
		result = 0;
	}
	ft_protected_mutex(&philo->philo_mutex, UNLOCK);
	return (result);
}

static int	ft_must_end_simulation(t_philo **philos)
{
	int	i;
	int	all_philos_full;

	i = 0;
	all_philos_full = 1;
	while (philos[i] != NULL)
	{
		if (ft_is_philo_dead(philos[i]))
			return (1);
		ft_protected_mutex(&philos[i]->philo_mutex, LOCK);
		if (philos[i]->table->limit_eat_nbr == -1
			|| philos[i]->eat_counter < philos[i]->table->limit_eat_nbr)
			all_philos_full = 0;
		ft_protected_mutex(&philos[i]->philo_mutex, UNLOCK);
		i++;
	}
	if (all_philos_full)
	{
		ft_protected_mutex(&philos[0]->table->table_mutex, LOCK);
		philos[0]->table->simulation_finished = 1;
		ft_protected_mutex(&philos[0]->table->table_mutex, UNLOCK);
		return (1);
	}
	return (all_philos_full);
}

int	ft_is_simulation_finished(t_table *table)
{
	int	result;

	ft_protected_mutex(&table->table_mutex, LOCK);
	result = table->simulation_finished;
	ft_protected_mutex(&table->table_mutex, UNLOCK);
	return (result);
}

void	ft_monitorize(t_table *table)
{
	while (1)
	{
		if (ft_must_end_simulation(table->philos))
		{
			break ;
		}
	}
}
