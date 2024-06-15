/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:16:35 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/24 12:16:35 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philo *philo)
{
	long	time;

	ft_protected_mutex(philo->first_fork, LOCK);
	ft_write(TAKE_FIRST_FORK, philo);
	ft_protected_mutex(philo->second_fork, LOCK);
	ft_write(TAKE_SECOND_FORK, philo);
	ft_protected_mutex(&philo->philo_mutex, LOCK);
	philo->last_eat_time = ft_running_time(philo->table);
	ft_protected_mutex(&philo->philo_mutex, UNLOCK);
	ft_write(EAT, philo);
	time = ft_running_time(philo->table) + philo->table->time_to_eat;
	while (ft_running_time(philo->table) < time)
	{
		if (ft_is_simulation_finished(philo->table))
		{
			break ;
		}
		usleep(1);
	}
	ft_protected_mutex(&philo->philo_mutex, LOCK);
	philo->eat_counter++;
	ft_protected_mutex(&philo->philo_mutex, UNLOCK);
	ft_protected_mutex(philo->first_fork, UNLOCK);
	ft_protected_mutex(philo->second_fork, UNLOCK);
}

void	ft_sleep(t_philo *philo)
{
	long	wake_up_time;

	ft_write(SLEEP, philo);
	wake_up_time = ft_running_time(philo->table) + philo->table->time_to_sleep;
	while (ft_running_time(philo->table) < wake_up_time)
	{
		if (ft_is_simulation_finished(philo->table))
		{
			break ;
		}
		usleep(1);
	}
}

void	ft_think(t_philo *philo)
{
	long	time_to_think;

	ft_protected_mutex(&philo->philo_mutex, LOCK);
	time_to_think = ft_running_time(philo->table) + (philo->table->time_to_die
			- philo->table->time_to_eat - philo->table->time_to_sleep) / 2;
	ft_protected_mutex(&philo->philo_mutex, UNLOCK);
	if (time_to_think <= 0)
	{
		time_to_think = 0;
	}
	ft_write(THINK, philo);
	while (ft_running_time(philo->table) < time_to_think)
	{
		if (ft_is_simulation_finished(philo->table))
		{
			break ;
		}
		usleep(1);
	}
}
