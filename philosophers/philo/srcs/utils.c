/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:21 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/13 23:26:22 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

uint64_t	get_time_ms(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		printf("gettimeofday() error\n");
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	destroy_mutexes(t_data *data)
{
	size_t	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&data->meals_lock);
	pthread_mutex_destroy(&data->signal_lock);
	pthread_mutex_destroy(&data->write_lock);
}

void	cleanup_philo(t_data *data)
{
	destroy_mutexes(data);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
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
