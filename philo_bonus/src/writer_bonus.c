/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:50:37 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:50:37 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_write(t_philo_status status, t_philo *philo)
{
	long	time;

	time = ft_running_time(philo->table);
	sem_wait(philo->table->writer);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK))
		printf("%-6ld %d has taken a fork\n", time, philo->id);
	else if (status == EAT)
		printf(MAGENTA"%-6ld %d is eating\n"PRINT, time, philo->id);
	else if (status == SLEEP)
		printf(GREEN"%-6ld %d is sleeping\n"PRINT, time, philo->id);
	else if (status == THINK)
		printf(GREEN"%-6ld %d is thinking\n"PRINT, time, philo->id);
	else if (status == DIED)
		printf(RED"%-6ld %d died\n"PRINT, time, philo->id);
	if (status != DIED)
		sem_post(philo->table->writer);
}
