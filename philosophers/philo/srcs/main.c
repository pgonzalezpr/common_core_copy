/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:14 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/14 00:30:09 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stddef.h>

int	check_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (printf("Invalid number of arguments\n"));
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (printf("Invalid input. %s is not numeric\n", argv[i]));
		if (i < 5 && ft_atoi(argv[i]) < 1)
			return (printf("Invalid input. %s is less than 1\n", argv[i]));
		i++;
	}
	return (0);
}

void	run_philos(t_data *data)
{
	size_t	i;

	if (data->min_eat_times == 0)
		return ;
	pthread_create(&data->monitor_id, NULL, monitor_routine, data);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_create(&data->philos[i].thread_id, NULL, philo_routine,
			&data->philos[i]);
		i++;
	}
	pthread_join(data->monitor_id, NULL);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv))
		return (1);
	if (init_data(argc, argv, &data))
		return (1);
	if (init_mutexes(&data))
		return (1);
	if (init_philos(&data))
		return (1);
	run_philos(&data);
	cleanup_philo(&data);
	return (0);
}

/*
#define ARR_SIZE 5
#define MAX_EAT 3
#define EAT_TIME 10000


typedef struct s_args
{
	pthread_mutex_t	*forks;
	int				index;
	int				*times_eaten;
	int				*signal;
}					t_args;

void	*exec_philo(void *args)
{
	t_args			*args_c;
	int				index;
	int				*times_eaten;
	int				*signal;
	int				first_index;
	int				second_index;
	struct timeval	tv;

	args_c = (t_args *) args;
	times_eaten = args_c->times_eaten;
	index = args_c->index;
	signal = args_c->signal;
	if (index % 2 == 0)
	{
		first_index = index;
		second_index = (index + 1) % ARR_SIZE;
	}
	else
	{
		first_index = (index + 1) % ARR_SIZE;
		second_index = index;
	}
	while (*signal == 0)
	{
		pthread_mutex_lock(&args_c->forks[first_index]);
		gettimeofday(&tv, NULL);
		printf("Philo %d picked fork %d at %d ms\n", index, first_index,
				tv.tv_usec/1000);
		pthread_mutex_lock(&args_c->forks[second_index]);
		gettimeofday(&tv, NULL);
		printf("Philo %d picked fork %d at %d ms\n", index, second_index,
				tv.tv_usec/1000);
		gettimeofday(&tv, NULL);
		printf("Philo %d is eating at %d ms\n", index, tv.tv_usec/1000);
		usleep(EAT_TIME);
		pthread_mutex_unlock(&args_c->forks[second_index]);
		gettimeofday(&tv, NULL);
		printf("Philo %d put fork %d down at %d ms\n", index, second_index,
				tv.tv_usec/1000);
		pthread_mutex_unlock(&args_c->forks[first_index]);
		gettimeofday(&tv, NULL);
		printf("Philo %d put fork %d down at %d ms\n", index, first_index,
				tv.tv_usec/1000);
		times_eaten[index]++;
		printf("Philo %d has eaten %d times\n", index, times_eaten[index]);
		if (times_eaten[index] == MAX_EAT)
			*signal = 1;
	}
	free(args);
	return (NULL);
}
*/
