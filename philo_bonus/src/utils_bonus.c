/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:50:32 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/25 12:50:32 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

char	*ft_check_input(char *str)
{
	int		len;
	char	*number;

	len = 0;
	if (!str)
		ft_exit_error(ERROR_MISSING_INPUT);
	while (ft_is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		ft_exit_error(ERROR_INPUT_NEGATIVE);
	if (!ft_is_digit(*str))
		ft_exit_error(ERROR_STRING_INPUT);
	number = str;
	while (ft_is_digit(*str))
	{
		str++;
		len++;
	}
	if (len > 10)
		ft_exit_error(ERROR_INPUT_TOO_BIG);
	return (number);
}

long	ft_current_ms_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		ft_exit_error(ERROR_GET_TIME);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	ft_running_time(t_table *table)
{
	return (ft_current_ms_time() - table->start_time);
}
