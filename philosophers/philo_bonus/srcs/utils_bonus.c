#include "../include/philo_bonus.h"

uint64_t	get_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_usleep(uint64_t ms)
{
	uint64_t	time;

	time = get_time_ms();
	while (get_time_ms() - time < ms)
		usleep(ms / 10);
}

void	print_log(int log_code, uint64_t index, uint64_t time, t_data *data)
{
	char	*msg;

	if (log_code == EAT_CODE)
		msg = "is_eating";
	if (log_code == THINK_CODE)
		msg = "is_thinking";
	if (log_code == SLEEP_CODE)
		msg = "is sleeping";
	if (log_code == FORK_CODE)
		msg = "has taken a fork";
	sem_wait(data->write_sem);
	printf("%lu %lu %s\n", time, index, msg);
	sem_post(data->write_sem);
}
