#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define THINK_CODE 1
# define EAT_CODE 2
# define SLEEP_CODE 3
# define FORK_CODE 4
# define DEATH_CODE 5
# define FORKS_NAME "/forks"
# define FORKS_SEM_NAME "/forks_sem"
# define WRITE_SEM_NAME "/write_sem"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	uint64_t			num_philos;
	uint64_t			time_to_die;
	uint64_t			time_to_sleep;
	uint64_t			time_to_eat;
	uint64_t			start_time;
	size_t				min_eat_times;
	pid_t				*process_ids;
	char				**sem_names;
	sem_t				**meal_sems;
	sem_t				*forks;
	sem_t				*forks_sem;
	sem_t				*write_sem;
}						t_data;

typedef struct s_philo
{
	t_data				*data;
	uint64_t			last_meal;
	uint64_t			index;
	uint64_t			meals;
	int					is_eating;
}						t_philo;

uint64_t				ft_atoi(const char *nptr);
uint64_t				get_time_ms(void);
int						is_numeric(char *str);
void					init_data(int argc, char **argv, t_data *data);
void					exit_philo(t_data *data, const char *msg, int status);
void					build_sem_names(t_data *data);
char					*ft_itoa(uint64_t nbr);
char					*ft_strjoin(const char *s1, const char *s2);
void					create_philos(t_data *data);
void					wait_philos(t_data *data);
void					ft_usleep(uint64_t ms);
void					print_log(int log_code, uint64_t index, uint64_t time,
							t_data *data);
void					take_forks(t_philo *philo);
void					eat(t_philo *philo);

#endif