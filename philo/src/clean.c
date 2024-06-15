/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:02:55 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/24 13:02:55 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_join(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_numbers)
	{
		ft_protected_thread(&table->philos[i]->thread, NULL, NULL, JOIN);
		i++;
	}
}

void	ft_clean(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_numbers)
	{
		ft_protected_mutex(&table->philos[i]->philo_mutex, DESTROY);
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
	i = 0;
	while (i < table->philo_numbers)
	{
		ft_protected_mutex(&table->forks[i], DESTROY);
		i++;
	}
	free(table->forks);
	ft_protected_mutex(&table->write_mutex, DESTROY);
	ft_protected_mutex(&table->table_mutex, DESTROY);
}
