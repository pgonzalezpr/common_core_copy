/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:58:56 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 13:59:30 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	min_greater_value(t_stack *stack, int value)
{
	int	min_greater;
	int	i;

	if (value > max_or_min(stack, "max") || value < max_or_min(stack, "min"))
		return (max_or_min(stack, "min"));
	i = 0;
	min_greater = INT_MAX;
	while (i < stack->size)
	{
		if (stack->values[i] > value && stack->values[i] < min_greater)
			min_greater = stack->values[i];
		i++;
	}
	return (min_greater);
}

int	max_smaller_value(t_stack *stack, int value)
{
	int	max_smaller;
	int	i;

	if (value > max_or_min(stack, "max") || value < max_or_min(stack, "min"))
		return (max_or_min(stack, "max"));
	i = 0;
	max_smaller = INT_MIN;
	while (i < stack->size)
	{
		if (stack->values[i] < value && stack->values[i] > max_smaller)
			max_smaller = stack->values[i];
		i++;
	}
	return (max_smaller);
}

int	dist_from_top(t_stack *stack, int idx)
{
	if (idx <= stack->size / 2)
		return (idx);
	else
		return (stack->size - idx);
}

int	count_inst(int a_idx, t_stack *stack_a, t_stack *stack_b)
{
	int	b_idx;
	int	b_max_smaller;
	int	a_dist;
	int	b_dist;

	b_max_smaller = max_smaller_value(stack_b, stack_a->values[a_idx]);
	b_idx = index_of(stack_b, b_max_smaller);
	a_dist = dist_from_top(stack_a, a_idx);
	b_dist = dist_from_top(stack_b, b_idx);
	if ((a_idx <= stack_a->size / 2 && b_idx <= stack_b->size / 2)
		|| (a_idx > stack_a->size / 2 && b_idx > stack_b->size / 2))
	{
		if (a_dist >= b_dist)
			return (a_dist);
		else
			return (b_dist);
	}
	return (a_dist + b_dist);
}
