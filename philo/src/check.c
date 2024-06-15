/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:28:09 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/23 17:28:09 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_process_input(t_table *table, char **argv)
{
	table->philo_numbers = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
	{
		table->limit_eat_nbr = ft_atol(argv[5]);
	}
	else
	{
		table->limit_eat_nbr = -1;
	}
	if (table->philo_numbers > 200)
		ft_exit_error(WARNING_MANY_PHILOS);
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
	{
		ft_exit_error(WARNING_LOW_TIME);
	}
}

long	ft_atol(char *str)
{
	int		i;
	long	number;

	str = ft_check_input(str);
	number = 0;
	i = 0;
	while (ft_is_digit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		if (number > INT_MAX)
			ft_exit_error(ERROR_INPUT_TOO_BIG);
		if (number == 0)
			ft_exit_error(ERROR_INPUT_NEGATIVE);
		i++;
	}
	if (str[i] && !ft_is_space(str[i]))
		ft_exit_error(ERROR_INVALID_INPUT);
	return (number);
}
