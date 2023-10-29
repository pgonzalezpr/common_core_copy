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
	exec_pipex(pipex_data);
	//print_pipex(pipex_data);
	exit_pipex(pipex_data, EXIT_SUCCESS);
}
