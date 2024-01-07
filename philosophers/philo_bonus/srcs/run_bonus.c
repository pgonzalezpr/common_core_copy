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

void	exec_philo(t_philo *philo)
{
	sem_wait(philo->data->write_sem);
	printf("%lu Hello from philo %lu\n", get_time_ms()
		- philo->data->start_time, philo->index);
	sem_post(philo->data->write_sem);
	exit(EXIT_SUCCESS);
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
		{
			philo.last_meal = get_time_ms();
			exec_philo(&philo);
		}
		i++;
	}
}
