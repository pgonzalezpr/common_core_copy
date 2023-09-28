#include "../include/utils.h"

int	find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int	idx;
	int	inst;
	int	min_inst;
	int	cheapest;

	idx = 0;
	min_inst = INT_MAX;
	cheapest = stack_a->values[0];
	while (idx < stack_a->size)
	{
		inst = count_inst(idx, stack_a, stack_b);
		if (inst < min_inst)
		{
			cheapest = stack_a->values[idx];
			min_inst = inst;
		}
		idx++;
	}
	return (cheapest);
}

void	push_cheapest(t_stack *stack_a, t_stack *stack_b, int cheapest)
{
	int	a_idx;
	int	b_idx;
	int	b_max_smaller;

	a_idx = index_of(stack_a, cheapest);
	b_max_smaller = max_smaller_value(stack_b, stack_a->values[a_idx]);
	b_idx = index_of(stack_b, b_max_smaller);
	if (a_idx <= stack_a->size / 2 && b_idx <= stack_b->size / 2)
		dual_rotate(stack_a, stack_b, cheapest, b_max_smaller);
	else if (a_idx > stack_a->size / 2 && b_idx > stack_b->size / 2)
		dual_reverse_rotate(stack_a, stack_b, cheapest, b_max_smaller);
	else
	{
		move_to_top(stack_a, cheapest, "ra\n", "rra\n");
		move_to_top(stack_b, b_max_smaller, "rb\n", "rrb\n");
	}
	push(stack_b, stack_a, "pb\n");
}

void	sort_three(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	else if (stack->size == 2)
		swap(stack, "sa\n");
	else if (stack->values[0] == max_or_min(stack, "min"))
	{
		swap(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	else if (stack->values[0] > stack->values[1]
		&& stack->values[1] > stack->values[2])
	{
		swap(stack, "sa\n");
		reverse_rotate(stack, "rra\n");
	}
	else if (stack->values[0] == max_or_min(stack, "max"))
		rotate(stack, "ra\n");
	else if (stack->values[0] > stack->values[1])
		swap(stack, "sa\n");
	else
		reverse_rotate(stack, "rra\n");
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	min_greater;
	int	idx;

	min_greater = min_greater_value(stack_a, stack_b->values[0]);
	idx = index_of(stack_a, min_greater);
	if (idx <= stack_a->size / 2)
	{
		while (stack_a->values[0] != min_greater)
			rotate(stack_a, "ra\n");
	}
	else
	{
		while (stack_a->values[0] != min_greater)
			reverse_rotate(stack_a, "rra\n");
	}
	push(stack_a, stack_b, "pa\n");
	return ;
}

void	move_min_top(t_stack *stack)
{
	int	min;
	int	min_idx;

	min = max_or_min(stack, "min");
	min_idx = index_of(stack, min);
	if (min_idx <= stack->size / 2)
	{
		while (stack->values[0] != min)
			rotate(stack, "ra\n");
	}
	else
	{
		while (stack->values[0] != min)
			reverse_rotate(stack, "rra\n");
	}
}
