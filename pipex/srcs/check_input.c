# include "../include/pipex.h"

int check_input(int argc, char **args)
{
    if (argc != 5)
    {
        ft_printf("Error. Incorrect number of arguments\n");
        return (0);
    }
    if (access(args[1], F_OK) != 0)
    {
        ft_printf("Error. File not found: %s\n", args[1]);
        return (0);
    }
    if (access(args[1], R_OK) != 0)
    {
        ft_printf("Error. Permission denied: %s\n", args[1]);
        return (0);
    }
    if (access(args[4], F_OK) == 0 && access(args[4], W_OK) != 0)
    {
        ft_printf("Error. Permission denied: %s\n", args[4]);
        return (0);
    }
    return (1);
}