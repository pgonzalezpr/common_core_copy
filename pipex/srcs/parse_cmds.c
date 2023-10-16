#include "../include/pipex.h"

char    *build_path(char *cmd, char * dir)
{
    char    *path;
    char    *tmp;

    path = ft_strjoin(dir, "/");
    if (!path)
        return (NULL);
    tmp = path;
    path = ft_strjoin(path, cmd);
    free(tmp);
    if (!path)
        return (NULL);
    return (path);
}

char    *check_cmd(char *input, char *dir)
{
    char    *path;
    char    **tokens;

    tokens = ft_split(input, ' ');
    if (!tokens)
        return (NULL);
    if (!tokens[0])
    {
        free_str_arr(tokens);
        return (NULL);
    }
    path = build_path(tokens[0], dir);
    if (access(path, X_OK != 0))
    {
        free_str_arr(tokens);
        free(path);
        return (NULL);
    }
    free_str_arr(tokens);
    return (path);
}

char	*get_cmd_path(char *input, char **envp)
{
	char	**path_dirs;
	char	*path;
    char    **tmp;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path_dirs = ft_split(*envp + 5, ':');
			if (!path_dirs)
				return (NULL);
            tmp = path_dirs;
			while (*path_dirs)
			{
				path = check_cmd(input, *path_dirs);
				if (path)
				{
					free_str_arr(tmp);
					return (path);
				}
				path_dirs++;
			}
			free_str_arr(tmp);
		}
        envp++;
	}
	return (NULL);
}

int	parse_cmds(char **argv, int argc, char **envp, t_pipex *pipex_data)
{
	int i;
	int start;
	char *path;
	char **cmd_paths;

	start = pipex_data->here_doc + 2;
	i = start;
	pipex_data->cmd_count = argc - 3 - pipex_data->here_doc;
	cmd_paths = malloc((pipex_data->cmd_count + 1) * sizeof(char *));
	if (!cmd_paths)
		return (0);
	pipex_data->cmd_paths = cmd_paths;
	while (i < argc - 1)
	{
		path = get_cmd_path(argv[i], envp);
		if (!path)
			return (0);
		cmd_paths[i - start] = path;
		i++;
	}
	cmd_paths[i - start] = NULL;
	return (1);
}