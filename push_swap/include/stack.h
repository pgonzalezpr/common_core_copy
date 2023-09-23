/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:02:15 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 14:02:16 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "utils.h"

typedef struct s_stack
{
	int	*values;
	int	size;
}		t_stack;

void	swap(t_stack *stack);
void	push(t_stack *stack, t_stack *other);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif // STACK_H
