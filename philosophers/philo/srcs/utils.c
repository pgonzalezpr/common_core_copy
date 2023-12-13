/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:21 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/11 13:14:04 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned int	get_philo_time(struct timeval *start_time)
{
	struct timeval	current_time;
	unsigned int	seconds_diff;
	unsigned int	useconds_diff;

    gettimeofday(&current_time, NULL);
    seconds_diff = current_time.tv_sec - start_time->tv_sec;
    useconds_diff = current_time.tv_usec - start_time->tv_usec;
    return (seconds_diff * 1000 + useconds_diff / 1000);
}

void	cleanup_philo(t_philo *philo_data)
{
	int	i;

	i = 0;
	while (i < philo_data->num_philos)
	{
		pthread_mutex_destroy(&philo_data->forks[i]);
		i++;
	}
	if (philo_data->philos)
		free(philo_data->philos);
	if (philo_data->forks)
		free(philo_data->forks);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

unsigned int	ft_atoi(const char *nptr)
{
	unsigned int	value;

	value = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (*nptr - '0');
		nptr++;
	}
	return (value);
}
