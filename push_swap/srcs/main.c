#include "../include/utils.h"

int	main(int argc, char **argv)
{
	int	*input_array;

	if (argc == 1)
		return (0);
	input_array = process_input(argv + 1, argc - 1);
	if (!input_array)
	{
		ft_printf("Error\n");
		return (0);
	}
	print_sort(input_array, argc - 1);
	free(input_array);
	return (1);
}
