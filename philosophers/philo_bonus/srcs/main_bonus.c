#include "../include/philo_bonus.h"

int	check_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (printf("Invalid number of arguments\n"));
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (printf("Invalid input. %s is not numeric\n", argv[i]));
		if (i < 5 && ft_atoi(argv[i]) < 1)
			return (printf("Invalid input. %s is less than 1\n", argv[i]));
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv))
		exit(EXIT_FAILURE);
	init_data(argc, argv, &data);
	create_philos(&data);
	wait_philos(&data);
	exit_philo(&data, NULL, EXIT_SUCCESS);
}
