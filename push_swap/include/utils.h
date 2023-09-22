#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "stack.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

int		*process_input(char **input, int len);
void	print_sort(int *arr, int len);
int     *zero_array(int len);
void    print_stack(t_stack *stack);
void    free_stack(t_stack *stack);

#endif // UTILS_H
