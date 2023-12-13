/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:40:25 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/11 20:46:39 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <bits/types/struct_timeval.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_MEALS 20

void	exec_philo(t_args *args, int first, int second)
{
	struct timeval	*start;
	int				meals;

	meals = 0;
	start = args->philo_data->start_time;
	while (!args->philo_data->end_signal)
	{
		pthread_mutex_lock(&args->philo_data->forks[first]);
		printf("%u ms %d has taken a fork\n", get_philo_time(start), args->idx);
		pthread_mutex_lock(&args->philo_data->forks[second]);
		printf("%u ms %d has taken a fork\n", get_philo_time(start), args->idx);
		printf("%u ms %d is eating, meals: %d\n", get_philo_time(start), args->idx, 
				meals);
		usleep(args->philo_data->time_to_eat * 1000);
		pthread_mutex_unlock(&args->philo_data->forks[second]);
		pthread_mutex_unlock(&args->philo_data->forks[first]);
		meals++;
		if (meals == MAX_MEALS)
		{
			args->philo_data->end_signal = 1;
			printf("%d is full\n", args->idx);
			break;
		}
	}
}

void	*philo_f(void *args)
{
	t_args	*args_c;
	int		first;
	int		second;
	
	args_c = (t_args *) args;
	if (args_c->idx % 2 == 0)
	{
		first = args_c->idx;
		second = (args_c->idx + 1) % args_c->philo_data->num_philos;
	}
	else
	{
		first = (args_c->idx + 1) % args_c->philo_data->num_philos;
		second = args_c->idx;
	
	}
	exec_philo(args_c, first, second);
	free(args);
	return (NULL);
}
