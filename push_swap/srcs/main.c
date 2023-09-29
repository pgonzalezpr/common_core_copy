/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:21 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 14:00:22 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	main(int argc, char **argv)
{
	int	*input_array;

	if (argc == 1)
		return (1);
	input_array = process_input(argv + 1, argc - 1);
	if (!input_array)
	{
		ft_printf("Error\n");
		return (1);
	}
	run_sort(input_array, argc - 1);
}
