/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:37 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/14 01:03:09 by pgonzalez        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	size_t				num_philos;
	uint64_t			time_to_die;
	uint64_t			time_to_sleep;
	uint64_t			time_to_eat;
	size_t				min_eat_times;
	int					signal;
	size_t				finished_count;
	t_philo				*philos;
	pthread_t			monitor_id;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		signal_lock;
	pthread_mutex_t		meals_lock;
}						t_data;

typedef struct s_philo
{
	t_data				*data;
	pthread_mutex_t		*first;
	pthread_mutex_t		*second;
	pthread_t			thread_id;
	uint64_t			last_meal;
	int					index;
}						t_philo;

uint64_t				ft_atoi(const char *nptr);
int						check_input(int argc, char **argv);
void					cleanup_philo(t_data *data);
uint64_t				get_time_ms(void);
int						init_data(int argc, char **argv, t_data *data);
int						init_mutexes(t_data *data);
int						init_philos(t_data *data);
int						is_numeric(char *str);
void					*monitor_routine(void *arg);
void					*philo_routine(void *arg);
int						check_end(t_data *data);
void					ph_eat(t_philo *philo);
void					ph_sleep(t_philo *philo);
void					ph_think(t_philo *philo);
void					print_log(int log_code, size_t philo_id, uint64_t time);

#endif
