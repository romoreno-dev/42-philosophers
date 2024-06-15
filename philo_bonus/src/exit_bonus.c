/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:49:55 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:49:55 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_exit_error(const char *error)
{
	printf(RED"%s\n"PRINT, error);
	printf("Remember examples of inputs:\n \
		./philo 3 200 300 300 6 \n \
		./philo 3 200 300 300 \n \
		Arguments:\n \
		- number_of_philosophers \n \
		- time_to_die_us(milliseconds, not less than 60ms) \n \
		- time_to_eat_us(milliseconds, not less than 60ms) \n \
		- time_to_sleep_us(milliseconds, not less than 60ms) \n \
		- [number_of_times_each_philosopher_must_eat](optional) \n");
	exit(EXIT_FAILURE);
}
