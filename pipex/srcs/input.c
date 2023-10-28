/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:18:04 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:21:28 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	check_permissions(char *infile, char *outfile)
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
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) != 0)
	{
		ft_printf("Error. Permission denied: %s\n", outfile);
		return (0);
	}
	return (1);
}

void	check_input(char **argv, int argc, t_pipex *pipex_data)
{
	int	in_fd;
	int	out_fd;

	if (argc != 5)
	{
		ft_printf("Error. Incorrect number of arguments\n");
		exit_pipex(pipex_data, EXIT_FAILURE);
	}
	if (!check_permissions(argv[1], argv[argc - 1]))
		exit_pipex(pipex_data, EXIT_FAILURE);
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (out_fd == -1)
		exit_pipex(pipex_data, EXIT_FAILURE);
	pipex_data->in_fd = in_fd;
	pipex_data->out_fd = out_fd;
}
