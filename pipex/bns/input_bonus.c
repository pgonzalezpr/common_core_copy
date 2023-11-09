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

void	here_doc(t_pipex *pipex_data)
{
	char	*input;
	char	*delimiter;

	delimiter = pipex_data->delimiter;
	while (1)
	{
		write(1, "> ", 2);
		input = get_next_line(1);
		if (!input || ft_strequals(input, delimiter))
			break ;
		if (write(pipex_data->pipe_fds[0][1], input, ft_strlen(input)) == -1)
			break ;
		free(input);
		input = NULL;
	}
	close_pipes(pipex_data);
	if (input)
		free(input);
	exit_pipex(pipex_data, EXIT_SUCCESS);
}

void	check_input(char **argv, int argc, char **envp, t_pipex *pipex_data)
{
	if (argc < 5 || (ft_strequals(argv[1], "here_doc") && argc < 6))
	{
		ft_printf(STDOUT_FILENO, "Error. Incorrect number of arguments\n");
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	pipex_data->here_doc = ft_strequals(argv[1], "here_doc");
	if (pipex_data->here_doc)
	{
		pipex_data->delimiter = ft_strjoin(argv[2], "\n");
		if (!pipex_data->delimiter)
			exit_pipex(pipex_data, EXIT_FAILURE);
	}
	else
		pipex_data->infile = argv[1];
	pipex_data->envp = envp;
	pipex_data->outfile = argv[argc - 1];
	pipex_data->cmd_count = argc - 3 - pipex_data->here_doc;
	pipex_data->pipe_fds = ft_calloc(pipex_data->cmd_count - 1
			+ pipex_data->here_doc, sizeof(int *));
	if (!pipex_data->pipe_fds)
		exit_pipex(pipex_data, EXIT_FAILURE);
}
