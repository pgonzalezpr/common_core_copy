/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:16:17 by pedro-go          #+#    #+#             */
/*   Updated: 2023/09/30 13:16:18 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils_bonus.h"

char	*get_input(void)
{
	char	*input;
	char	*clean_input;

	input = get_next_line(1);
	if (!input)
		return (NULL);
	clean_input = ft_strtrim(input, "\n");
	free(input);
	return (clean_input);
}

size_t	max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

int	is_valid_inst(char **str_arr, char *str)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str);
	ft_strtrim(str, "\n");
	while (str_arr[i] != NULL)
	{
		if (ft_strncmp(str_arr[i], str, max(str_len,
					ft_strlen(str_arr[i]))) == 0)
			return (1);
		i++;
	}
	free_str_arr(str_arr);
	free(str);
	ft_putstr_fd("Error \n", 2);
	return (0);
}

void	apply_inst(t_stack *stack_a, t_stack *stack_b, char *inst)
{
	if (ft_strncmp(inst, "sa", max(ft_strlen(inst), 2)) == 0)
		swap(stack_a, NULL);
	else if (ft_strncmp(inst, "sb", max(ft_strlen(inst), 2)) == 0)
		swap(stack_b, NULL);
	else if (ft_strncmp(inst, "ss", max(ft_strlen(inst), 2)) == 0)
		dual_swap(stack_a, stack_b, NULL);
	else if (ft_strncmp(inst, "pa", max(ft_strlen(inst), 2)) == 0)
		push(stack_a, stack_b, NULL);
	else if (ft_strncmp(inst, "pb", max(ft_strlen(inst), 2)) == 0)
		push(stack_b, stack_a, NULL);
	else if (ft_strncmp(inst, "ra", max(ft_strlen(inst), 2)) == 0)
		rotate(stack_a, NULL);
	else if (ft_strncmp(inst, "rb", max(ft_strlen(inst), 2)) == 0)
		rotate(stack_b, NULL);
	else if (ft_strncmp(inst, "rr", max(ft_strlen(inst), 2)) == 0)
		dual_rotate(stack_a, stack_b, NULL);
	else if (ft_strncmp(inst, "rra", max(ft_strlen(inst), 3)) == 0)
		reverse_rotate(stack_a, NULL);
	else if (ft_strncmp(inst, "rrb", max(ft_strlen(inst), 3)) == 0)
		reverse_rotate(stack_b, NULL);
	else if (ft_strncmp(inst, "rrr", max(ft_strlen(inst), 3)) == 0)
		dual_reverse_rotate(stack_a, stack_b, NULL);
}
