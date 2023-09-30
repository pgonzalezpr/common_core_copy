/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:16:32 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/30 13:16:33 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	dual_rotate(t_stack *stack_a, t_stack *stack_b, int a_value,
		int b_value)
{
	while (stack_a->values[0] != a_value && stack_b->values[0] != b_value)
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
		ft_printf("rr\n");
	}
	while (stack_a->values[0] != a_value)
		rotate(stack_a, "ra\n");
	while (stack_b->values[0] != b_value)
		rotate(stack_b, "rb\n");
}

void	dual_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int a_value,
		int b_value)
{
	while (stack_a->values[0] != a_value && stack_b->values[0] != b_value)
	{
		reverse_rotate(stack_a, NULL);
		reverse_rotate(stack_b, NULL);
		ft_printf("rrr\n");
	}
	while (stack_a->values[0] != a_value)
		reverse_rotate(stack_a, "rra\n");
	while (stack_b->values[0] != b_value)
		reverse_rotate(stack_b, "rrb\n");
}

void	move_to_top(t_stack *stack, int value, char *r_msg, char *rr_msg)
{
	int	idx;

	idx = index_of(stack, value);
	if (idx <= stack->size / 2)
	{
		while (stack->values[0] != value)
			rotate(stack, r_msg);
	}
	else
	{
		while (stack->values[0] != value)
			reverse_rotate(stack, rr_msg);
	}
}
