#include "../includes/utils.h"

/*
char	*get_three_inst(int *stack)
{
}

char	*get_inst(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
}

char	*get_inst_set(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	if (len == 1)
		return (NULL);
	if (len == 2)
	{
		if (stack_a[0] > stack_a[1])
		{
			stack_swap(stack_a); // Create this funcion, stack_utils.h
			return ("sa\n");
		}
		return (NULL);
	}
	if (len == 3)
		return (get_three_inst(stack_a));
	return (get_inst(stack_a, stack_b, len_a, len_b));
}

void	build_stack(int *stack, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i] = arr[i];
		i++;
	}
}

void	print_sort(int *arr, int len)
{
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		len_b;
	char	*instruction_set;

	stack_a = malloc(len * sizeof(int));
	if (!stack_a)
		return ;
	stack_b = malloc(len * sizeof(int));
	if (!stack_b)
		return ;
	build_stack(stack_a, arr, len);
	len_a = len;
	len_b = 0;
	inst_set = get_inst_set(stack_a, stack_b, &len_a, &len_b);
	while (instruction_set)
	{
		ft_printf("%s", inst_set);
		inst_set = get_ins_set(stack_a, stack_b, &len_a, &len_b);
	}
	free(stack_a);
	free(stack_b);
	if (inst_set)
		free(inst_set);
}
*/

void	print_sort(int *arr, int len)
{
	int	i;
	
	i = 0;
	while (i < len)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
}
