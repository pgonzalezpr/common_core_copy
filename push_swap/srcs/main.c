#include "../include/utils.h"

int	main(int argc, char **argv)
{
	int	*input_array;
	
	if (argc == 1)
		return (0);
	input_array = process_input(argv + 1, argc - 1);
	if (!input_array)
	{
		ft_printf("Error\n");
		return (0);
	}

	/*
	print_sort(input_array, argc - 1);
	free(input_array);
	*/

	t_stack	*stack_a = malloc(sizeof(t_stack));
	t_stack *stack_b = malloc(sizeof(t_stack));
	stack_a->values = input_array;
	stack_a->size = argc - 1;
	stack_b->values = zero_array(argc - 1);
	stack_b->size = 0;

	push(stack_b, stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);

	rotate(stack_a);
	rotate(stack_a);
	
	reverse_rotate(stack_b);
	reverse_rotate(stack_b);

	swap(stack_a);
	swap(stack_b);

	push(stack_a, stack_b);
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	push(stack_a, stack_b);

	print_stack(stack_a);
	print_stack(stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}
