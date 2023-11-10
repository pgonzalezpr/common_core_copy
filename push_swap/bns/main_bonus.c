/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:03:16 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 14:03:17 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/utils_bonus.h"

int	main(int argc, char **argv)
{
	int		*input_array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	input_array = process_input(argv + 1, argc - 1);
	if (!input_array)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = new_stack(input_array, argc - 1);
	if (!stack_a)
		exit(1);
	stack_b = new_stack(ft_calloc(argc - 1, sizeof(int)), 0);
	if (!stack_b)
	{
		free_stack(stack_a);
		exit(1);
	}	
	run_push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
