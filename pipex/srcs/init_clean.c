#include "../include/pipex.h"

t_pipex	*init_pipex(void)
{
	t_pipex	*pipex_data;

	pipex_data = malloc(sizeof(t_pipex));
	if (!pipex_data)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->in_fd = -1;
	pipex_data->out_fd = -1;
	pipex_data->input_fd = open(USR_INPUT_FILE, O_RDWR | O_CREAT,
			S_IRUSR | S_IWUSR);
	if (pipex_data->input_fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->tmp_fd = open(TMP_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (pipex_data->tmp_fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->here_doc = 0;
	pipex_data->cmd_paths = NULL;
	pipex_data->cmd_args = NULL;
	pipex_data->cmd_count = 0;
	return (pipex_data);
}

void	free_str_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_params(char ***args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free_str_arr(args[i]);
		i++;
	}
	free(args);
}

void	exit_pipex(t_pipex *pipex_data, int status)
{
	if (pipex_data->in_fd >= 0)
		close(pipex_data->in_fd);
	if (pipex_data->out_fd >= 0)
		close(pipex_data->out_fd);
	if (pipex_data->input_fd >= 0)
		close(pipex_data->input_fd);
	if (pipex_data->tmp_fd >= 0)
		close(pipex_data->tmp_fd);
	if (pipex_data->cmd_paths)
		free_str_arr(pipex_data->cmd_paths);
	if (pipex_data->cmd_args)
		free_params(pipex_data->cmd_args);
	free(pipex_data);
	//unlink(TMP_FILE);
	//unlink(USR_INPUT_FILE);
	exit(status);
}
