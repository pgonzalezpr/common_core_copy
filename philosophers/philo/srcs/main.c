/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:14 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/09 13:27:16 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_data(int argc, char **argv, t_philo *philo_data)
{
	memset(philo_data, 0, sizeof(t_philo));
	philo_data->num_philos = ft_atoi(argv[1]);
	philo_data->time_to_die = ft_atoi(argv[2]);
	philo_data->time_to_eat = ft_atoi(argv[3]);
	philo_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_data->min_eat_times = ft_atoi(argv[5]);
	philo_data->philos = malloc(philo_data->num_philos * sizeof(pthread_t));
	if (!philo_data->philos)
		return (0);
	philo_data->forks = malloc(philo_data->num_philos
			* sizeof(pthread_mutex_t));
	if (!philo_data->forks)
	{
		free(philo_data->philos);
		return (0);
	}
	return (1);
}

void	run_philos(t_philo *philo_data)
{
	int		i;
	int		idx;
	t_args	*args;

	i = 0;
	while (i < philo_data->num_philos)
	{
		args = malloc(sizeof(t_args));
		if (!args)
			break ;
		args->philo_data = philo_data;
		args->idx = i;
		if (pthread_create(&philo_data->philos[i], NULL, exec_ph, args) == -1)
		{
			free(args);
			break ;
		}
		i++;
	}
	idx = 0;
	while (idx < i)
	{
		pthread_join(philo_data->philos[i], NULL);
		idx++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	philo_data;
	int		i;

	if (!check_input(argc, argv))
	{
		printf("Invalid input\n");
		return (1);
	}
	if (!init_data(argc, argv, &philo_data))
		return (1);
	i = 0;
	while (i < philo_data.num_philos)
	{
		pthread_mutex_init(&philo_data.forks[i], NULL);
		i++;
	}
	run_philos(&philo_data);
	cleanup_philo(&philo_data);
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

int	main(void)
{
	int				i;
	t_args			*args;
	pthread_t		philos[ARR_SIZE];
	pthread_mutex_t	forks[ARR_SIZE];
	int				times_eaten[ARR_SIZE];
	int				signal;

	memset(philos, 0, ARR_SIZE * sizeof(pthread_t));
	memset(forks, 0, ARR_SIZE * sizeof(pthread_mutex_t));
	memset(times_eaten, 0, ARR_SIZE * sizeof(int));
	signal = 0;
	i = 0;
	while (i < ARR_SIZE)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < ARR_SIZE)
	{
		args = malloc(sizeof(t_args));
		args->forks = forks;
		args->times_eaten = times_eaten;
		args->index = i;
		args->signal = &signal;
		if (pthread_create(&philos[i], NULL, exec_philo, args) != 0)
		{
			perror("Error creating thread");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < ARR_SIZE)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	i = 0;
	while (i < ARR_SIZE)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
*/
