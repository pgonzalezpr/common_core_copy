/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:14 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/16 14:59:09 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

int	run_philos(t_data *data)
{
	size_t	i;

	if (data->min_eat_times == 0)
		return (1);
	i = 0;
	data->start_time = get_time_ms();
	if (pthread_create(&data->monitor_id, NULL, monitor_routine, data) != 0)
		return (printf("Error creating monitor thread\n"));
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, philo_routine,
				&data->philos[i]) != 0)
			break ;
		i++;
	}
	pthread_join(data->monitor_id, NULL);
	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].thread_id != 0)
			pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv))
		return (1);
	if (init_data(argc, argv, &data) || init_mutexes(&data)
		|| init_philos(&data) || run_philos(&data))
	{
		cleanup_philo(&data);
		return (1);
	}
	cleanup_philo(&data);
	return (0);
}
