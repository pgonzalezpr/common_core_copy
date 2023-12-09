/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:40:25 by pedro-go          #+#    #+#             */
/*   Updated: 2023/12/09 14:40:26 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*exec_ph(void *args)
{
	t_args	args_c;

	args_c = *(t_args *)args;
	printf("Hello from philo %d, philos: %p\n",
		args_c.idx + 1, args_c.philo_data->philos);
	free(args);
	return (NULL);
}
