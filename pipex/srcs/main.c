/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-go <pedro-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:18:14 by pedro-go          #+#    #+#             */
/*   Updated: 2023/10/28 17:18:15 by pedro-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex_data;

	pipex_data = init_pipex();
	check_input(argv, argc, pipex_data);
	parse_cmds(argv, argc, envp, pipex_data);
	parse_args(argv, argc, pipex_data);
	// print_pipex(pipex_data);
	exec_pipex(pipex_data);
	exit_pipex(pipex_data, EXIT_SUCCESS);
}

/*
if (!(argc && argv && envp))
	exit(EXIT_FAILURE);
int	fd = open(USR_INPUT_FILE, O_RDWR | O_CREAT,
		S_IRUSR | S_IWUSR);
int	fd2 = open(TMP_FILE, O_RDWR | O_CREAT,
		S_IRUSR | S_IWUSR);
ft_printf("fd: %d, fd2: %d\n", fd, fd2);
*/
