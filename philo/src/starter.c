/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:44:44 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/23 18:44:44 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_routine(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!ft_is_simulation_finished(philo->table))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	*ft_one_philo_routine(void *param)
{
	t_philo	*philo;

	philo = param;
	ft_write(TAKE_FIRST_FORK, philo);
	while (ft_running_time(philo->table) - philo->last_eat_time
		< philo->table->time_to_die)
	{
	}
	return (NULL);
}

void	ft_start_philos(t_table *table)
{
	int	i;

	i = 0;
	if (table->philo_numbers == 1)
	{
		ft_protected_thread(&table->philos[0]->thread, ft_one_philo_routine,
			table->philos[0], CREATE);
	}
	else
	{
		while (i < table->philo_numbers)
		{
			ft_protected_thread(&table->philos[i]->thread, ft_routine,
				table->philos[i], CREATE);
			i++;
			usleep(50);
		}
	}
}
