/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:49:33 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:49:33 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_eat(t_philo *philo)
{
	long	time;

	sem_wait(philo->table->forks);
	ft_write(TAKE_FIRST_FORK, philo);
	if (philo->table->philo_numbers == 1)
	{
		sem_wait(philo->last_eat_variable);
		while (ft_running_time(philo->table) - philo->last_eat_time
			< philo->table->time_to_die)
		{
		}
		sem_post(philo->last_eat_variable);
	}
	sem_wait(philo->table->forks);
	ft_write(TAKE_SECOND_FORK, philo);
	sem_wait(philo->last_eat_variable);
	philo->last_eat_time = ft_running_time(philo->table);
	sem_post(philo->last_eat_variable);
	ft_write(EAT, philo);
	time = ft_running_time(philo->table) + philo->table->time_to_eat;
	while (ft_running_time(philo->table) < time)
		usleep(1);
	philo->eat_counter++;
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
}

void	ft_sleep(t_philo *philo)
{
	long	wake_up_time;

	ft_write(SLEEP, philo);
	wake_up_time = ft_running_time(philo->table) + philo->table->time_to_sleep;
	while (ft_running_time(philo->table) < wake_up_time)
	{
		usleep(1);
	}
}

void	ft_think(t_philo *philo)
{
	long	time_to_think;

	time_to_think = ft_running_time(philo->table) + (philo->table->time_to_die
			- philo->table->time_to_eat - philo->table->time_to_sleep) / 2;
	if (time_to_think <= 0)
	{
		time_to_think = 0;
	}
	ft_write(THINK, philo);
	while (ft_running_time(philo->table) < time_to_think)
	{
		usleep(1);
	}
}
