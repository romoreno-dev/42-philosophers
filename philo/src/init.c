/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:41:24 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/23 17:41:24 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_numbers)
	{
		table->philos[i] = ft_protected_malloc(sizeof(t_philo));
		table->philos[i]->id = i + 1;
		table->philos[i]->eat_counter = 0;
		table->philos[i]->table = table;
		table->philos[i]->last_eat_time = ft_running_time(table);
		ft_protected_mutex(&table->philos[i]->philo_mutex, INIT);
		i++;
	}
}

void	ft_init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_numbers)
	{
		ft_protected_mutex(&table->forks[i], INIT);
		i++;
	}
}

void	ft_assign_forks(t_table *table)
{
	int				i;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*rigth_fork;

	i = 0;
	while (i < table->philo_numbers)
	{
		if (i != 0)
			left_fork = &table->forks[i - 1];
		else
			left_fork = &table->forks[table->philo_numbers - 1];
		rigth_fork = &table->forks[i];
		if (table->philos[i]->id % 2 == 0)
		{
			table->philos[i]->first_fork = left_fork;
			table->philos[i]->second_fork = rigth_fork;
		}
		else
		{
			table->philos[i]->first_fork = rigth_fork;
			table->philos[i]->second_fork = left_fork;
		}
		i++;
	}
}

void	ft_init_table(t_table *table)
{
	table->start_time = ft_current_ms_time();
	table->simulation_finished = 0;
	table->philos = ft_protected_malloc(table->philo_numbers
			* sizeof(t_philo));
	table->forks = ft_protected_malloc(table->philo_numbers
			* sizeof(pthread_mutex_t));
	ft_protected_mutex(&table->table_mutex, INIT);
	ft_protected_mutex(&table->write_mutex, INIT);
}
