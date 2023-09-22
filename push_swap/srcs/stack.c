#include "../include/utils.h"

void    swap(t_stack *stack)
{
    int tmp;

    if (stack->size > 1)
    {
        tmp = stack->values[0];
        stack->values[0] = stack->values[1];
        stack->values[1] = tmp;
    }
}

void    push(t_stack *stack, t_stack *other)
{
    if (other->size > 0)
    {
        ft_memmove(&stack->values[1], &stack->values[0],
        stack->size * sizeof(int));
        stack->values[0] = other->values[0];
        stack->size++;
        ft_memmove(&other->values[0], &other->values[1], 
        (other->size - 1) * sizeof(int));
        other->size--;
    }
}

void    rotate(t_stack *stack)
{
    int first;

    if (stack->size > 0)
    {
        first = stack->values[0];
        ft_memmove(&stack->values[0], &stack->values[1], 
        (stack->size - 1) * sizeof(int));
        stack->values[stack->size - 1] = first;
    }
}

void    reverse_rotate(t_stack *stack)
{
    int last;

    if (stack->size > 0)
    {
        last = stack->values[stack->size - 1];
        ft_memmove(&stack->values[1], &stack->values[0],
        (stack->size - 1) * sizeof(int));
        stack->values[0] = last;
    }
}