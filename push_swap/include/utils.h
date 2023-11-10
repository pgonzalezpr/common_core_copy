/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:02:20 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/23 14:02:21 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "stack.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

int		*process_input(char **input, int len);
void	run_sort(int *arr, int len);
void	free_stack(t_stack *stack);
t_stack	*new_stack(int *arr, int size);
int		is_sorted(t_stack *stack);
int		find_cheapest(t_stack *stack_a, t_stack *stack_b);
void	push_cheapest(t_stack *stack_a, t_stack *stack_b, int cheapest);
void	sort_three(t_stack *stack);
void	push_back(t_stack *stack_a, t_stack *stack_b);
int		max_or_min(t_stack *stack, char *flag);
int		min_greater_value(t_stack *stack, int value);
int		max_smaller_value(t_stack *stack, int value);
int		index_of(t_stack *stack, int value);
int		dist_from_top(t_stack *stack, int idx);
int		count_inst(int a_idx, t_stack *stack_a, t_stack *stack_b);
void	dual_rotate(t_stack *stack_a, t_stack *stack_b, int a_value,
			int b_value);
void	dual_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int a_value,
			int b_value);
void	move_to_top(t_stack *stack, int value, char *r_msg, char *rr_msg);

#endif // UTILS_H
