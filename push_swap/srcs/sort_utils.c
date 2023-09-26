#include "../include/utils.h"

int     find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
    return (1);
}

void    push_cheapest(t_stack *stack_a, t_stack *stack_b, int cheapest)
{
    return ;
}

void    sort_three(t_stack *stack)
{
    if (is_sorted(stack))
        return ;
    else if (stack->size == 2)
        ft_printf("%s", swap(stack));
    else if (stack->values[0] == max_or_min(stack, "min"))
    {
        swap(stack);
        rotate(stack);
    }
    else if (stack->values[0] > stack->values[1] && 
    stack->values[1] > stack->values[2])
    {
        swap(stack);
        reverse_rotate(stack);
    }
    else if (stack->values[0] == max_or_min(stack, "max"))
        rotate(stack);
    else if (stack->values[0] > stack->values[1])
        swap(stack);
    else
        reverse_rotate(stack);
}

void    push_back(t_stack *stack_a, t_stack *stack_b)
{
    return ;
}

void    move_min_top(t_stack *stack)
{
    return ;
}