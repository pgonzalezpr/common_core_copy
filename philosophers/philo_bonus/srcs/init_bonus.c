/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:37:28 by pedro-go          #+#    #+#             */
/*   Updated: 2024/04/13 18:37:30 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	build_sem_names(t_data *data)
{
	uint64_t	i;
	char		*first;
	char		*second;

	first = "/meal_sem_";
	i = 0;
	while (i < data->num_philos)
	{
		second = ft_itoa(i);
		if (!second)
			exit_philo(data, "malloc() error\n", EXIT_FAILURE);
		data->sem_names[i] = ft_strjoin(first, second);
		free(second);
		if (!data->sem_names[i])
			exit_philo(data, "malloc() error\n", EXIT_FAILURE);
		i++;
	}
}

void	init_semaphores(t_data *data)
{
	uint64_t	i;

	i = 0;
	build_sem_names(data);
	destroy_sems(data);
	while (i < data->num_philos)
	{
		data->meal_sems[i] = sem_open(data->sem_names[i], O_CREAT, 0644, 1);
		if (data->meal_sems[i] == SEM_FAILED)
			exit_philo(data, "sem_open() error\n", EXIT_FAILURE);
		i++;
	}
	data->forks = sem_open(FORKS_NAME, O_CREAT, 0644, data->num_philos);
	data->forks_sem = sem_open(FORKS_SEM_NAME, O_CREAT, 0644, 1);
	data->write_sem = sem_open(WRITE_SEM_NAME, O_CREAT, 0644, 1);
	if (data->forks == SEM_FAILED || data->forks_sem == SEM_FAILED
		|| data->write_sem == SEM_FAILED)
		exit_philo(data, "sem_open() error\n", EXIT_FAILURE);
}

void	init_data(int argc, char **argv, t_data *data)
{
	memset(data, 0, sizeof(t_data));
	data->num_philos = (size_t)ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->min_eat_times = ft_atoi(argv[5]);
	else
		data->min_eat_times = -1;
	data->process_ids = malloc(data->num_philos * sizeof(pid_t));
	data->meal_sems = malloc(data->num_philos * sizeof(sem_t *));
	data->sem_names = malloc(data->num_philos * sizeof(char *));
	if (!data->process_ids || !data->meal_sems || !data->sem_names)
		exit_philo(data, "malloc() error\n", EXIT_FAILURE);
	memset(data->process_ids, 0, data->num_philos * sizeof(pid_t));
	memset(data->meal_sems, 0, data->num_philos * sizeof(sem_t *));
	memset(data->sem_names, 0, data->num_philos * sizeof(char *));
	init_semaphores(data);
}
