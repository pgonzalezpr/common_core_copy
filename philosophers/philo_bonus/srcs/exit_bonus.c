#include "../include/philo_bonus.h"

void	free_str_arr(char **arr, uint64_t size)
{
	uint64_t	i;

	if (!arr)
		return ;
	i = 0;
	while (i < size)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	destroy_sems(t_data *data)
{
	uint64_t	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (data->sem_names && data->sem_names[i])
			sem_unlink(data->sem_names[i]);
		i++;
	}
	sem_unlink(FORKS_NAME);
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(WRITE_SEM_NAME);
}

void	close_sems(t_data *data)
{
	uint64_t	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (data->meal_sems && data->meal_sems[i])
			sem_close(data->meal_sems[i]);
		i++;
	}
	sem_close(data->forks);
	sem_close(data->forks_sem);
	sem_close(data->write_sem);
}

void	exit_philo(t_data *data, const char *msg, int status)
{
	close_sems(data);
	destroy_sems(data);
	free_str_arr(data->sem_names, data->num_philos);
	if (data->process_ids)
		free(data->process_ids);
	if (data->meal_sems)
		free(data->meal_sems);
	if (msg)
		printf("%s", msg);
	exit(status);
}
