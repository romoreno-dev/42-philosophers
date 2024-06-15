/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:22:50 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/26 11:22:50 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	count_characters(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	long		aux_num;
	int			length;
	int			index_begin_digits;
	char		*digits;

	aux_num = n;
	index_begin_digits = 0;
	length = count_characters(aux_num);
	if (aux_num < 0)
	{
		aux_num = -aux_num;
		index_begin_digits = 1;
	}
	digits = (char *) malloc((sizeof(char) * (length + 1)));
	if (digits == NULL)
		return (NULL);
	digits[length] = '\0';
	digits[0] = '-';
	while (length > index_begin_digits)
	{
		digits[length - 1] = ((aux_num % 10) + 48);
		aux_num = aux_num / 10;
		length--;
	}
	return (digits);
}
