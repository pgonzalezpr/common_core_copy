#include "../include/philo_bonus.h"

void	kill_philos(t_data *data)
{
	uint64_t	i;

	i = 0;
	while (i < data->num_philos)
	{
		kill(data->process_ids[i], SIGKILL);
		i++;
	}
}

void	*monitor_routine(void *arg)
{
	t_philo		*philo;
	uint64_t	time;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->meal_sems[philo->index - 1]);
		time = get_time_ms() - philo->data->start_time;
		if (time - philo->last_meal > philo->data->time_to_die
			&& !philo->is_eating)
		{
			sem_wait(philo->data->write_sem);
			printf("%lu %lu has died\n", time, philo->index);
			exit(EXIT_FAILURE);
		}
		sem_post(philo->data->meal_sems[philo->index - 1]);
	}
	return ((void *)0);
}

void	exec_philo(t_philo *philo)
{
	pthread_t	monitor_id;

	if (philo->data->min_eat_times == 0)
		exit(EXIT_SUCCESS);
	if (pthread_create(&monitor_id, NULL, monitor_routine, philo) != 0)
	{
		sem_wait(philo->data->write_sem);
		printf("Error creating monitor thread\n");
		sem_post(philo->data->write_sem);
		exit(EXIT_FAILURE);
	}
	philo->last_meal = get_time_ms() - philo->data->start_time;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		print_log(SLEEP_CODE, philo->index, get_time_ms()
			- philo->data->start_time, philo->data);
		ft_usleep(philo->data->time_to_sleep);
		print_log(THINK_CODE, philo->index, get_time_ms()
			- philo->data->start_time, philo->data);
	}
}

void	wait_philos(t_data *data)
{
	uint64_t	count;
	int			status;

	count = 0;
	while (count < data->num_philos)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == EXIT_FAILURE)
		{
			kill_philos(data);
			break ;
		}
		count++;
	}
}

void	create_philos(t_data *data)
{
	t_philo		philo;
	uint64_t	i;

	memset(&philo, 0, sizeof(t_philo));
	philo.data = data;
	i = 0;
	data->start_time = get_time_ms();
	while (i < data->num_philos)
	{
		philo.index = i + 1;
		data->process_ids[i] = fork();
		if (data->process_ids[i] < 0)
		{
			sem_wait(data->write_sem);
			printf("fork() error\n");
			sem_post(data->write_sem);
			kill_philos(data);
		}
		if (data->process_ids[i] == 0)
			exec_philo(&philo);
		i++;
	}
	destroy_sems(data);
}
