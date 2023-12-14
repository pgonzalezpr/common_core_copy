/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:40:25 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/14 00:57:52 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

int	check_end(t_data *data)
{
}

void	check_times(t_data *data)
{
}

void	check_meals(t_data *data)
{
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!check_end(data))
	{
		pthread_mutex_lock(&data->meals_lock);
		check_times(data);
		check_meals(data);
		pthread_mutex_unlock(&data->meals_lock);
	}
	return ((void *)0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_end(philo->data))
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return ((void *)0);
}
