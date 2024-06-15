/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:50:26 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:50:26 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_philo_process_routine(void *param)
{
	t_philo	*philo;

	philo = param;
	ft_protected_thread(philo->check_dead_th,
		ft_philo_monitor_routine, philo, CREATE);
	ft_protected_thread(philo->check_dead_th,
		NULL, NULL, DETACH);
	if (philo->id % 2 == 0)
	{
		usleep(1000);
	}
	while (1)
	{
		sem_wait(philo->can_eat);
		ft_eat(philo);
		sem_post(philo->can_eat);
		ft_sleep(philo);
		ft_think(philo);
	}
}

void	ft_start_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_numbers)
	{
		table->pid[i] = fork();
		if (table->pid[i] == 0)
		{
			ft_philo_process_routine(table->philos[i]);
		}
		i++;
	}
}
