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
