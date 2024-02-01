#include "../include/philo_bonus.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks_sem);
	sem_wait(philo->data->forks);
	print_log(FORK_CODE, philo->index, get_time_ms() - philo->data->start_time,
		philo->data);
	if (philo->data->num_philos == 1)
	{
		ft_usleep(philo->data->time_to_die);
		sem_wait(philo->data->write_sem);
		printf("%lu %lu has died\n", get_time_ms() - philo->data->start_time,
			philo->index);
		sem_post(philo->data->forks);
		exit_philo(philo->data, NULL, EXIT_FAILURE);
	}
	sem_wait(philo->data->forks);
	print_log(FORK_CODE, philo->index, get_time_ms() - philo->data->start_time,
		philo->data);
	sem_post(philo->data->forks_sem);
}

void	eat(t_philo *philo)
{
	uint64_t	time;

	time = get_time_ms() - philo->data->start_time;
	print_log(EAT_CODE, philo->index, time, philo->data);
	sem_wait(philo->data->meal_sems[philo->index - 1]);
	philo->is_eating = 1;
	philo->last_meal = time;
	philo->meals++;
	sem_post(philo->data->meal_sems[philo->index - 1]);
	ft_usleep(philo->data->time_to_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	sem_wait(philo->data->meal_sems[philo->index - 1]);
	philo->is_eating = 0;
	if (philo->meals >= philo->data->min_eat_times)
		exit(EXIT_SUCCESS);
	sem_post(philo->data->meal_sems[philo->index - 1]);
}
