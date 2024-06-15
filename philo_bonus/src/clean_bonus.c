/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:49:48 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:49:48 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_kill_all_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_numbers)
	{
		kill(table->pid[i], SIGTERM);
		i++;
	}
}

void	ft_clean(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_numbers)
	{
		sem_close(table->philos[i]->can_eat);
		sem_close(table->philos[i]->last_eat_variable);
		free(table->philos[i]->check_dead_th);
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
	free(table->pid);
	free(table->monitor);
	sem_close(table->forks);
	sem_close(table->writer);
	sem_close(table->finished);
}
