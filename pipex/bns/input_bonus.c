/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:18:57 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:19:04 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	}
	free(delimiter);
	return (input);
}

void	get_input(char *delimiter, t_pipex *pipex_data)
{
	char	*input;
	int		here_doc_fd;

	here_doc_fd = open(USR_INPUT_FILE, O_WRONLY);
	if (here_doc_fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	input = read_input(ft_strjoin(delimiter, "\n"));
	if (!input)
	{
		close(here_doc_fd);
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	if (write(here_doc_fd, input, ft_strlen(input)) == -1)
	{
		close(here_doc_fd);
		free(input);
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	free(input);
	close(here_doc_fd);
}

void	open_fds(char **argv, int argc, t_pipex *pipex_data)
{
	if (pipex_data->here_doc)
	{
		get_input(argv[2], pipex_data);
		pipex_data->in_fd = open(USR_INPUT_FILE, O_RDONLY);
		pipex_data->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR);
		if (pipex_data->in_fd == -1 || pipex_data->out_fd == -1)
			exit_pipex(pipex_data, EXIT_FAILURE);
		return ;
	}
	pipex_data->in_fd = open(argv[1], O_RDONLY);
	pipex_data->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (pipex_data->in_fd == -1 || pipex_data->out_fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
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
	open_fds(argv, argc, pipex_data);
}
