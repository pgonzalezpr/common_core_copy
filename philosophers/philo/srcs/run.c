/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:40:25 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/16 14:57:05 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_signal(t_data *data)
{
	int	value;

	value = 0;
	pthread_mutex_lock(&data->signal_lock);
	if (data->signal)
		value = 1;
	pthread_mutex_unlock(&data->signal_lock);
	return (value);
}

void	check_times_meals(t_data *data)
{
	size_t		i;
	size_t		finished_count;
	uint64_t	time;

	i = 0;
	finished_count = 0;
	while (i < data->num_philos)
	{
		time = get_time_ms() - data->start_time;
		if (time - data->philos[i].last_meal > data->time_to_die
			&& !data->philos[i].is_eating)
			print_log(DEATH_CODE, data->philos[i].index, time, data);
		if (data->philos[i].meals >= data->min_eat_times)
			finished_count++;
		i++;
	}
	if (finished_count == data->num_philos)
	{
		pthread_mutex_lock(&data->signal_lock);
		data->signal = 1;
		pthread_mutex_unlock(&data->signal_lock);
	}
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!check_signal(data))
	{
		pthread_mutex_lock(&data->meals_lock);
		check_times_meals(data);
		pthread_mutex_unlock(&data->meals_lock);
	}
	return ((void *)0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time_ms() - philo->data->start_time;
	while (!check_signal(philo->data))
	{
		ph_eat(philo);
		print_log(SLEEP_CODE, philo->index, get_time_ms()
			- philo->data->start_time, philo->data);
		ft_usleep(philo->data->time_to_sleep);
		print_log(THINK_CODE, philo->index, get_time_ms()
			- philo->data->start_time, philo->data);
	}
	return ((void *)0);
}
