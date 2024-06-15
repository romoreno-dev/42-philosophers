/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:23:02 by romoreno          #+#    #+#             */
/*   Updated: 2024/03/26 11:23:02 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	length_dst;
	size_t	length_src;

	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	i = 0;
	j = length_dst;
	if (dstsize == 0 || dstsize <= length_dst)
		return (length_src + dstsize);
	while (src[i] != '\0' && i < (dstsize - length_dst - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (length_src + length_dst);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	int		index;
	char	*str;

	index = 0;
	str = (char *) b;
	while (index < (int)len)
	{
		str[index] = c;
		index++;
	}
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length_new_str;
	char	*new_str;

	length_new_str = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (length_new_str + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memset(new_str, 0, length_new_str + 1);
	if (length_new_str == 0)
		return (new_str);
	ft_strlcat(new_str, s1, length_new_str + 1);
	ft_strlcat(new_str, s2, length_new_str + 1);
	return (new_str);
}
