/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:55:05 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/18 14:55:42 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	append_outfile(t_sep *sep)
{
	int	fd_out;

	fd_out = -1;
	if (ft_strncmp(sep->rd_out, ">>", 2) == 0)
		fd_out = open(sep->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (ft_strncmp(sep->rd_out, ">", 1) == 0)
		fd_out = open(sep->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror(RED"Failed to open output file"RST);
		shell_exit(EXIT_FAILURE);
	}
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perror(RED"Failed to duplicate file descriptor"RST);
		shell_exit(EXIT_FAILURE);
	}
	close(fd_out);
	return (EXIT_SUCCESS);
}

void	exec_redir_out_pipe(t_sep *sep, char *pathname, char **argv, char **env)
{
	pid_t	pid;
	int		fd_in;

	if (sep->file_in)
	{
		if ((fd_in = open(sep->file_in, O_RDONLY)) == -1)
			shell_exit(EXIT_FAILURE);
		if (dup2(fd_in, STDIN_FILENO) == -1)
			shell_exit(EXIT_FAILURE);
		close(fd_in);
	}
	if (sep->file_out)
	{
		if (ft_strncmp(sep->rd_out, ">>", 2) == 0)
			append_outfile(sep);
		else if (ft_strncmp(sep->rd_out, ">", 1) == 0)
			if (handle_outfile(sep) != EXIT_SUCCESS)
				shell_exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(RED"Failed to fork"RST);
		shell_exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(pathname, argv, env) == -1)
		{
			perror(RED"Failed to execute command"RST);
			shell_exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, NULL, 0);
}

void	exec_redir_in_child(t_sep *sep, char *pathname, char **argv, char **env)
{
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	fd_in = STDIN_FILENO;
	if (sep->file_in)
	{
		if ((fd_in = open(sep->file_in, O_RDONLY)) == -1)
			exit(EXIT_FAILURE);
	}
	fd_out = STDOUT_FILENO;
	if (sep->file_out)
	{
		if (ft_strncmp(sep->rd_out, ">>", 2) == 0)
			fd_out = open(sep->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (ft_strncmp(sep->rd_out, ">", 1) == 0)
			fd_out = open(sep->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out == -1)
			exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_in);
		close(fd_out);
		execve(pathname, argv, env);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}

void	exec_redir_in(t_sep *sep, char *pathname, char **argv, char **env)
{
	pid_t	pid;
	int		fd;

	if (sep->file_in)
		if ((fd = open(sep->file_in, O_RDONLY)) == -1)
			shell_exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		shell_exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		execve(pathname, argv, env);
		perror("execve");
		shell_exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}
