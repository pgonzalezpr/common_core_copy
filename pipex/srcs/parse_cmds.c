# include "../include/pipex.h"



int parse_cmds(char **argv, int argc, t_pipex *pipex_data)
{
    int     i;
    int     start;
    int     cmd_count;
    char    *path;
    char    **cmd_paths;

    start = pipex_data->here_doc + 1;
    i = start;
    cmd_count = argc - 3 - pipex_data->here_doc;
    cmd_paths = malloc((cmd_count + 1) * sizeof(char *));
    if (!cmd_paths)
        return (0);
    pipex_data->cmd_paths = cmd_paths;
    while (i < argc - 1)
    {
        path = get_cmd_path(argv[i]);
        if (!path)
            return (0);
        cmd_paths[i - start] = path;
        i++;
    }
    cmd_paths[i - start] = NULL;
    return (1);
}