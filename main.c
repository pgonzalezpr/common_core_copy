#include "include/ft_printf_bonus.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	x1;
	int	x2;

	x1 = ft_printf("%-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("\n");
	x2 = printf("%-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d, %-+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("\n");
	printf("returned: %d, expected: %d\n", x1, x2);
}
