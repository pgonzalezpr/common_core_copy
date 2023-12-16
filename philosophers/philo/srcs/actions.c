/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:26:52 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/16 14:15:03 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->first);
	print_log(FORK_CODE, philo->index, get_time_ms() - philo->data->start_time,
			philo->data);
	usleep(philo->data->time_to_die * 1000);
	print_log(DEATH_CODE, philo->index, get_time_ms() - philo->data->start_time,
			philo->data);
	pthread_mutex_unlock(philo->first);
}

void	print_log(int log_code, size_t index, uint64_t time, t_data *data)
{
	char	*msg;

	if (log_code == EAT_CODE)
		msg = "is_eating";
	if (log_code == THINK_CODE)
		msg = "is_thinking";
	if (log_code == SLEEP_CODE)
		msg = "is sleeping";
	if (log_code == FORK_CODE)
		msg = "has taken a fork";
	if (log_code == DEATH_CODE)
		msg = "has died";
	pthread_mutex_lock(&data->write_lock);
	if (!check_signal(data))
		printf("%lu %zu %s\n", time, index, msg);
	if (log_code == DEATH_CODE)
	{
		pthread_mutex_lock(&data->signal_lock);
		data->signal = 1;
		pthread_mutex_unlock(&data->signal_lock);
	}
	pthread_mutex_unlock(&data->write_lock);
}

void	ph_eat(t_philo *philo)
{
	uint64_t	time;

	if (philo->data->num_philos == 1)
	{
		one_philo(philo);
		return ;
	}
	pthread_mutex_lock(philo->first);
	print_log(FORK_CODE, philo->index, get_time_ms() - philo->data->start_time,
			philo->data);
	pthread_mutex_lock(philo->second);
	print_log(FORK_CODE, philo->index, get_time_ms() - philo->data->start_time,
			philo->data);
	time = get_time_ms() - philo->data->start_time;
	print_log(EAT_CODE, philo->index, time, philo->data);
	pthread_mutex_lock(&philo->data->meals_lock);
	philo->is_eating = 1;
	philo->last_meal = get_time_ms() - philo->data->start_time;
	philo->meals++;
	if (philo->meals >= philo->data->min_eat_times)
		philo->finished = 1;
	pthread_mutex_unlock(&philo->data->meals_lock);
	ft_usleep(philo->data->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->second);
	pthread_mutex_unlock(philo->first);
}
