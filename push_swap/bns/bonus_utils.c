#include "../include/bonus_utils.h"

int	is_sorted(t_stack *stack)
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

void	run_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;
	char	**valid_inst;

	valid_inst = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	if (!valid_inst)
		return ;
	while (1)
	{
		input = get_input();
		if (!input)
			break ;
		if (!is_valid_inst(valid_inst, input))
			return ;
		apply_inst(stack_a, stack_b, input);
	}
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_str_arr(valid_inst);
	free(input);
	return ;
}
