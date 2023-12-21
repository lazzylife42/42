/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:46:34 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/21 15:47:28 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(char **cmd1_arg, char **env, int *fd, char **directory)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute(cmd1_arg, directory, env);
}

void	parent_process(char **cmd2_arg, char **env, int *fd, char **directory)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute(cmd2_arg, directory, env);
}

int	exec_pipe(char **cmd1_arg, char **cmd2_arg, char **env, char **directory)
{
	int pipe_fd[2];
	pid_t pid;

	if (pipe(pipe_fd) == -1)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		return (-1);
	}

	if (pid == 0)
	{
		child_process(cmd1_arg, env, pipe_fd, directory);
	}
	else
	{
		parent_process(cmd2_arg, env, pipe_fd, directory);
		wait(NULL);
	}
	return (0);
}
