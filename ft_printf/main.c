#include <stdio.h>
#include <stdlib.h>
#include "include/ft_printf_bonus.h"
#include <limits.h>

int	main()
{
	int x1 = ft_printf("%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("\n");
	int x2 = printf("%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("\n");
	printf("returned: %d, expected: %d\n", x1, x2);
}	
