/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:26:03 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/23 17:26:03 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		ft_exit_error(ERROR_MISSING_ARGS_INPUT);
	}
	ft_process_input(&table, argv);
	ft_init_table(&table);
	ft_init_philos(&table);
	ft_init_forks(&table);
	ft_assign_forks(&table);
	ft_start_philos(&table);
	ft_monitorize(&table);
	usleep(50);
	ft_join(&table);
	ft_clean(&table);
}
