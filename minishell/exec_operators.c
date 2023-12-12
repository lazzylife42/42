/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:25:02 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/12 11:07:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pipe(char *command1, char *command2, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if(execute(command1, env) == -1)
			return (-1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (execute(command2, env) == -1)
			return (-1);
	}
	return (0);
}

int	execute_redir_out(char *command1, char *command2, char **env)
{
	int		fd_out;
	pid_t	pid;

	fd_out = open(command2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		if(execute(command1, env) == -1)
			return (-1);
	}
	else
	{
		wait(NULL);
		close(fd_out);
	}
	return (0);
}

int	execute_redir_append(char *command1, char *command2, char **env)
{
	int		fd_out;
	pid_t	pid;

	fd_out = open(command2, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_out == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		if(execute(command1, env) == -1)
			return (-1);
	}
	else
	{
		wait(NULL);
		close(fd_out);
	}
	return (0);
}

int	execute_redir_in(char *command1, char *command2, char **env)
{
	int		fd_in;
	pid_t	pid;

	fd_in = open(command2, O_RDONLY);
	if (fd_in == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		if(execute(command1, env) == -1)
			return (-1);
	}
	else
	{
		wait(NULL);
		close(fd_in);
	}
	return (0);
}
