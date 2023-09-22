#ifndef STACK_H
# define STACK_H

#include "utils.h"

typedef struct s_stack
{
    int *values;
    int size;
}   t_stack;

void    swap(t_stack *stack);
void    push(t_stack *stack, t_stack *other);
void    rotate(t_stack *stack);
void    reverse_rotate(t_stack *stack);

#endif //STACK_H