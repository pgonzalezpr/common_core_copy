/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:00:40 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 14:00:41 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	cheapest;

	if (stack_a->size <= 3)
		sort_three(stack_a);
	else
	{
		push(stack_b, stack_a, "pb\n");
		push(stack_b, stack_a, "pb\n");
		while (stack_a->size > 3)
		{
			cheapest = find_cheapest(stack_a, stack_b);
			push_cheapest(stack_a, stack_b, cheapest);
		}
		sort_three(stack_a);
		while (stack_b->size > 0)
			push_back(stack_a, stack_b);
		move_to_top(stack_a, max_or_min(stack_a, "min"), "ra\n", "rra\n");
	}
}

void	run_sort(int *arr, int len)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = new_stack(arr, len);
	if (!stack_a)
		exit(1);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		exit(1);
	}
	stack_b = new_stack(ft_calloc(len, sizeof(int)), 0);
	if (!stack_b)
	{
		free_stack(stack_a);
		exit(1);
	}
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
