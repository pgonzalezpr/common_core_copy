/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:38:51 by pedro-go          #+#    #+#             */
/*   Updated: 2024/04/13 18:38:52 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_copy;

	if (!src && !dest)
		return (dest);
	dest_copy = dest;
	while (n > 0)
	{
		*((char *)dest++) = *((char *)src++);
		n--;
	}
	return (dest_copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[size - 1] = '\0';
	return (ptr);
}

char	*ft_itoa(uint64_t nbr)
{
	uint64_t	nbr_cpy;
	char		*str;
	int			digits;

	nbr_cpy = nbr;
	digits = 0;
	while (nbr_cpy >= 10)
	{
		digits++;
		nbr_cpy = nbr_cpy / 10;
	}
	digits++;
	str = malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[digits--] = '\0';
	while (nbr >= 10)
	{
		str[digits--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str[digits--] = nbr + '0';
	return (str);
}

uint64_t	ft_atoi(const char *nptr)
{
	uint64_t	value;

	value = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (*nptr - '0');
		nptr++;
	}
	return (value);
}
