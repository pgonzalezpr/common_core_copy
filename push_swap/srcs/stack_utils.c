/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:01:43 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 14:01:44 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int		is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->values[i] > stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int     max_or_min(t_stack *stack, char *flag)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (i < stack->size)
	{
		if (stack->values[i] > max)
			max = stack->values[i];
		if (stack->values[i] < min)
			min = stack->values[i];
		i++;
	}
	if (ft_strncmp(flag, "max", 3) == 0)
		return (max);
	if (ft_strncmp(flag, "min", 3) == 0)
		return (min);
	return (-1);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
		ft_printf("%d ", stack->values[i++]);
	ft_printf("\n");
	ft_printf("Size = %d\n", stack->size);
}

void	free_stack(t_stack *stack)
{
	free(stack->values);
	free(stack);
}

t_stack	*new_stack(int *arr, int size)
{
	t_stack	*stack;

	if (!arr)
		return (NULL);
	stack = malloc(sizeof(stack));
	if (!stack)
		return (NULL);
	stack->values = arr;
	stack->size = size;
	return (stack);
}
