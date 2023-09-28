/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:01:10 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 14:01:11 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	swap(t_stack *stack, char *msg)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->values[0];
		stack->values[0] = stack->values[1];
		stack->values[1] = tmp;
		if (msg)
			ft_printf("%s", msg);
	}
}

void	push(t_stack *stack, t_stack *other, char *msg)
{
	if (other->size > 0)
	{
		ft_memmove(&stack->values[1], &stack->values[0], stack->size
			* sizeof(int));
		stack->values[0] = other->values[0];
		stack->size++;
		ft_memmove(&other->values[0], &other->values[1], (other->size - 1)
			* sizeof(int));
		other->size--;
		if (msg)
			ft_printf("%s", msg);
	}
}

void	rotate(t_stack *stack, char *msg)
{
	int	first;

	if (stack->size > 0)
	{
		first = stack->values[0];
		ft_memmove(&stack->values[0], &stack->values[1], (stack->size - 1)
			* sizeof(int));
		stack->values[stack->size - 1] = first;
		if (msg)
			ft_printf("%s", msg);
	}
}

void	reverse_rotate(t_stack *stack, char *msg)
{
	int	last;

	if (stack->size > 0)
	{
		last = stack->values[stack->size - 1];
		ft_memmove(&stack->values[1], &stack->values[0], (stack->size - 1)
			* sizeof(int));
		stack->values[0] = last;
		if (msg)
			ft_printf("%s", msg);
	}
}
