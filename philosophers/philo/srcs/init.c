/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:26:58 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/14 16:26:59 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_data(int argc, char **argv, t_data *data)
{
	memset(data, 0, sizeof(t_data));
	data->num_philos = (size_t)ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->min_eat_times = (size_t)ft_atoi(argv[5]);
	else
		data->min_eat_times = -1;
	data->philos = malloc(data->num_philos * sizeof(t_philo));
	data->forks = malloc(data->num_philos * sizeof(pthread_mutex_t));
	if (!data->philos || !data->forks)
	{
		cleanup_philo(data);
		return (printf("Allocation error\n"));
	}
	return (0);
}

int	init_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (printf("Mutex init error\n"));
		i++;
	}
	if (pthread_mutex_init(&data->meals_lock, NULL) != 0
		|| pthread_mutex_init(&data->write_lock, NULL) != 0
		|| pthread_mutex_init(&data->signal_lock, NULL) != 0)
		return (printf("Mutex init error\n"));
	return (0);
}

int	init_philos(t_data *data)
{
	size_t	i;

	memset(data->philos, 0, data->num_philos * sizeof(t_philo));
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].data = data;
		data->philos[i].index = i + 1;
		data->philos[i].first = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].second = &data->forks[i];
		if (i % 2 == 0)
		{
			data->philos[i].first = &data->forks[i];
			data->philos[i].second = &data->forks[(i + 1) % data->num_philos];
		}
		i++;
	}
	return (0);
}
