/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:37 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/09 13:27:38 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_TIME_MS "1000"

typedef struct s_philo
{
	int				num_philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				min_eat_times;
	int				end_signal;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
}					t_philo;

typedef struct s_args
{
	t_philo			*philo_data;
	int				idx;
}					t_args;

int					ft_atoi(const char *nptr);
int					check_input(int argc, char **argv);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				cleanup_philo(t_philo *philo_data);
void				*exec_ph(void *args);

#endif
