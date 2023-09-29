#include "../include/bonus_utils.h"

void	dual_swap(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	if (msg)
		ft_printf("%s", msg);
}

void	dual_rotate(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (msg)
		ft_printf("%s", msg);
}

void	dual_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	if (msg)
		ft_printf("%s", msg);
}
