#include "../include/utils.h"

int     find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a && stack_b)
        return (1);
    return (0);
}

void    push_cheapest(t_stack *stack_a, t_stack *stack_b, int cheapest)
{
    if (stack_a && stack_b && cheapest)
        ft_printf("YES!");
}

void    sort_three(t_stack *stack)
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
    else if (stack->values[0] > stack->values[1] && 
    stack->values[1] > stack->values[2])
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

void    push_back(t_stack *stack_a, t_stack *stack_b)
{
    int min_greater;
    int idx;

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

void    move_min_top(t_stack *stack)
{
    int min;
    int min_idx;

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