/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:39:45 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/23 17:39:45 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_calloc(size_t bytes)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(bytes);
	if (!ptr)
	{
		ft_exit_error(ERROR_MALLOC);
	}
	i = 0;
	while (i < (bytes))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *) ptr);
}

void	*ft_protected_malloc(size_t bytes)
{
	void	*output;

	output = ft_calloc(bytes);
	if (!output)
		ft_exit_error(ERROR_MALLOC);
	return (output);
}

void	ft_protected_mutex(pthread_mutex_t *mutex, t_mutex_option option)
{
	int	result;

	result = -1;
	if (option == LOCK)
		result = pthread_mutex_lock(mutex);
	else if (option == UNLOCK)
		result = pthread_mutex_unlock(mutex);
	else if (option == INIT)
		result = pthread_mutex_init(mutex, NULL);
	else if (option == DESTROY)
		result = pthread_mutex_destroy(mutex);
	if (result != 0)
	{
		ft_exit_error(ERROR_MUTEX);
	}
}

void	ft_protected_thread(pthread_t *thread, void *(*routine)(void *),
	void *data, t_thread_option option)
{
	int	result;

	result = -1;
	if (option == CREATE)
	{
		result = pthread_create(thread, NULL, routine, data);
	}
	else if (option == JOIN)
	{
		result = pthread_join(*thread, NULL);
	}
	else if (option == DETACH)
	{
		result = pthread_detach(*thread);
	}
	if (result != 0)
	{
		ft_exit_error(ERROR_THREAD);
	}
}
