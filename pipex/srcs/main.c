#include "../include/pipex.h"

int main(int argc, char **argv)
{
    char    *infile;
    char    *outfile;

    if (!check_input(argc, argv))
        return (1);
    infile = argv[1];
    outfile = argv[4];
    ft_printf("Files OK. %s , %s\n", infile, outfile);
}