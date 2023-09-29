#ifndef BONUS_UTILS_H
# define BONUS_UTILS_H

# include "libft.h"
# include "stack.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

int		*process_input(char **input, int len);
char	*get_input(void);
int		*zero_array(int len);
void	free_stack(t_stack *stack);
t_stack	*new_stack(int *arr, int size);
int		is_sorted(t_stack *stack);
void	run_push_swap(t_stack *stack_a, t_stack *stack_b);
void	free_str_arr(char **str_arr);
int		is_valid_inst(char **str_arr, char *str);
void	apply_inst(t_stack *stack_a, t_stack *stack_b, char *inst);
void	dual_swap(t_stack *stack_a, t_stack *stack_b, char *msg);
void	dual_rotate(t_stack *stack_a, t_stack *stack_b, char *msg);
void	dual_reverse_rotate(t_stack *stack_a, t_stack *stack_b, char *msg);

#endif // BONUS_UTILS_H