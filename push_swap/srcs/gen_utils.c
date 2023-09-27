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
	if (stack && value)
		return (1);
	return (0);
}

int	index_of(t_stack *stack, int value)
{
	int	idx;

	idx = 0;
	while (idx < stack->size)
	{
		if (stack->values[idx] == value)
			return (idx);
		idx++;
	}
	return (-1);
}

int	*zero_array(int len)
{
	int	*arr;

	if (len <= 0)
		return (NULL);
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	while (len > 0)
		arr[--len] = 0;
	return (arr);
}
