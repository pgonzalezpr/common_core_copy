#include "include/ft_printf_bonus.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	x1;
	int	x2;

	x1 = ft_printf("%5.0x", 0);
	printf("\n");
	x2 = printf("%5.0x", 0);
	printf("\n");
	printf("returned: %d, expected: %d\n", x1, x2);
}
