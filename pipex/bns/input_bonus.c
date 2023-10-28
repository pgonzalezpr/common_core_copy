#include "../include/pipex_bonus.h"

int	check_permissions(char *infile, char *outfile, t_pipex *pipex_data)
{
	if (!pipex_data->here_doc)
	{
		if (access(infile, F_OK) != 0)
		{
			ft_printf("Error. File not found: %s\n", infile);
			return (0);
		}
		if (access(infile, R_OK) != 0)
		{
			ft_printf("Error. Permission denied: %s\n", infile);
			return (0);
		}
	}
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) != 0)
	{
		ft_printf("Error. Permission denied: %s\n", outfile);
		return (0);
	}
	return (1);
}

char	*read_input(char *delimiter)
{
	char	*input;
	char	*tmp;
	char	*buffer;

	input = ft_strdup("");
	if (!input || !delimiter)
		return (NULL);
	buffer = get_next_line(1);
	while (buffer)
	{
		if (ft_strequals(buffer, delimiter))
		{
			free(buffer);
			break ;
		}
		tmp = input;
		input = ft_strjoin(input, buffer);
		free(tmp);
		free(buffer);
		buffer = get_next_line(1);
	return (input);
}

void	get_input(char *delimiter, t_pipex *pipex_data)
{
	char	*input;

	input = read_input(ft_strjoin(delimiter, "\n"));
	if (!input)
		exit_pipex(pipex_data, EXIT_FAILURE);
	if (write(pipex_data->in_fd, input, ft_strlen(input)) == -1)
	{
		free(input);
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	free(input);
}

void	open_fds(char **argv, int argc, t_pipex *pipex_data)
{
	int	out_fd;

	if (pipex_data->here_doc)
	{
		get_input(argv[2], pipex_data);
		
	}
}

void	check_input(char **argv, int argc, t_pipex *pipex_data)
{
	int	in_fd;
	int	out_fd;

	if (!pipex_data->here_doc)
	{
		in_fd = open(argv[1], O_RDONLY);
		if (in_fd == -1)
			return (0);
		pipex_data->in_fd = in_fd;
		out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		if (out_fd == -1)
			return (0);
		pipex_data->out_fd = out_fd;
		return (1);
	}
	pipex_data->in_fd = pipex_data->input_fd;
	pipex_data->input_fd = -1;
	get_input(argv[2], pipex_data);
	out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR);
	if (out_fd == -1)
		return (0);
	pipex_data->out_fd = out_fd;
	return (1);
}

void	check_input(char **argv, int argc, t_pipex *pipex_data)
{
	pipex_data->here_doc = ft_strequals(argv[1], "here_doc");
	if (argc < 5 || (pipex_data->here_doc && argc < 6))
	{
		ft_printf("Error. Incorrect number of arguments\n");
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	if (!check_permissions(argv[1], argv[argc - 1], pipex_data))
		exit_pipex(pipex_data, EXIT_FAILURE);
	if (!open_fds(argv, argc, pipex_data))
		exit_pipex(pipex_data, EXIT_FAILURE);
}
