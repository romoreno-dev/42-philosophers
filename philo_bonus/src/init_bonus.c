/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:50:00 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:50:00 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_init_philos(t_table *table)
{
	int		i;
	char	*i_str;
	char	*sem;

	i = 0;
	while (i < table->philo_numbers)
	{
		table->philos[i] = ft_protected_malloc(sizeof(t_philo));
		table->philos[i]->id = i + 1;
		table->philos[i]->eat_counter = 0;
		table->philos[i]->table = table;
		table->philos[i]->last_eat_time = ft_running_time(table);
		table->philos[i]->check_dead_th = ft_protected_malloc(sizeof(t_philo));
		i_str = ft_itoa(table->philos[i]->id);
		sem = ft_strjoin(SEM_LAST_EAT, i_str);
		sem_unlink(sem);
		table->philos[i]->last_eat_variable = sem_open(sem, O_CREAT, 0777, 1);
		free(sem);
		sem = ft_strjoin(SEM_CAN_EAT, i_str);
		sem_unlink(sem);
		table->philos[i]->can_eat = sem_open(sem, O_CREAT, 0777, 1);
		free(i_str);
		free(sem);
		i++;
	}
}

void	ft_init_forks(t_table *table)
{
	sem_unlink(SEM_FORKS);
	table->forks = sem_open(SEM_FORKS, O_CREAT, 0777, table->philo_numbers);
}

void	ft_init_table(t_table *table)
{
	table->start_time = ft_current_ms_time();
	table->simulation_finished = 0;
	table->philos = ft_protected_malloc(table->philo_numbers
			* sizeof(t_philo));
	table->pid = ft_protected_malloc(table->philo_numbers
			* sizeof(pid_t));
	table->monitor = ft_protected_malloc(sizeof(t_philo));
	sem_unlink(SEMAPHORE_WRITER);
	table->writer = sem_open(SEMAPHORE_WRITER, O_CREAT, 0777, 1);
	sem_unlink(SEMAPHORE_FINISHED);
	table->finished = sem_open(SEMAPHORE_FINISHED, O_CREAT, 0777, 1);
	sem_wait(table->finished);
}
