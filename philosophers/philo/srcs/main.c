#include "../include/philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define ARR_SIZE 5
#define MAX_EAT 3
#define EAT_TIME 10000

typedef struct s_args
{
	pthread_mutex_t	*forks;
	int				index;
	int				*times_eaten;
	int				*signal;
} t_args;

void	*exec_philo(void *args)
{
	t_args	*args_c;
	int		index;
	int		*times_eaten;
	int		*signal;
	int		first_index;
	int		second_index;

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
		printf("Philo %d picked fork %d\n", index, first_index);
		pthread_mutex_lock(&args_c->forks[second_index]);
		printf("Philo %d picked fork %d\n", index, second_index);
		printf("Philo %d is eating\n", index);
		usleep(EAT_TIME);
		pthread_mutex_unlock(&args_c->forks[second_index]);
		printf("Philo %d put fork %d down\n", index, second_index);
		pthread_mutex_unlock(&args_c->forks[first_index]);
		printf("Philo %d put fork %d down\n", index, first_index);
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
