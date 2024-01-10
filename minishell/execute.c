/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:24:49 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/10 20:08:03 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execve_to_child(char *pathname, char **argv, char **env)
// a virer (mais pour l'instant est appelé par le parent)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		execve(pathname, argv, env);
	else
		waitpid(pid, NULL, 0);
}

// void	exec_redir(t_sep *sep, char *pathname, char **argv, char **env)
// {
// 	pid_t	pid;
// 	int		fd_in;
// 	int		fd_out;

// 	fd_in = STDIN_FILENO;
// 	fd_out = STDOUT_FILENO;
// 	if (sep->file_in && sep->rd_in)
// 	{
// 		fd_in = open(sep->file_in, O_RDONLY);
// 		if (fd_in == -1)
// 			exit(EXIT_FAILURE);
// 		if (dup2(fd_in, STDIN_FILENO) == -1)
// 			exit(EXIT_FAILURE);
// 		close(fd_in);
// 	}
// 	if (sep->file_out && sep->rd_out)
// 	{
// 		if (ft_strncmp(sep->rd_out, ">>", 2) == 0)
// 			fd_out = open(sep->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 		else if (ft_strncmp(sep->rd_out, ">", 1) == 0)
// 			fd_out = open(sep->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (fd_out == -1)
// 			exit(EXIT_FAILURE);
// 		if (dup2(fd_out, STDOUT_FILENO) == -1)
// 			exit(EXIT_FAILURE);
// 		close(fd_out);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 		exit(EXIT_FAILURE);
// 	if (pid == 0)
// 	{
// 		execve(pathname, argv, env);
// 		perror("Exec error");
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 		waitpid(pid, NULL, 0);
// }

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
	{
		if ((fd = open(sep->file_in, O_RDONLY)) == -1)
			exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		execve(pathname, argv, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}

// void	exec_redir_out(t_sep *sep, char *pathname, char **argv, char **env)
// {
// 	pid_t	pid;
// 	int		fd;

// 	if (ft_strncmp(sep->rd_out, ">>", 2) == 0)
// 	{
// 		if ((fd = open(sep->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644)) ==
// 			-1)
// 			exit(EXIT_FAILURE);
// 	}
// 	else if (ft_strncmp(sep->rd_out, ">", 1) == 0)
// 	{
// 		if ((fd = open(sep->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644)) ==
// 			-1)
// 			exit(EXIT_FAILURE);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 		exit(EXIT_FAILURE);
// 	if (pid == 0)
// 	{
// 		dup2(fd, STDOUT_FILENO);
// 		close(fd);
// 		execve(pathname, argv, env);
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 		waitpid(pid, NULL, 0);
// }

void	execute(char **input, char **directory, char ***env, t_sep *sep)
{
	char	*txt;

	txt = translate_quote(input[0], *env);
	if (ft_strncmp(txt, "echo", 5) == 0)
		echo(input + 1, env);
	else if (ft_strncmp(txt, "pwd", 4) == 0)
		printf("%s\n", *directory);
	else if (ft_strncmp(txt, "exit", 5) == 0)
		exit(0);
	else if (ft_strncmp(txt, "export", 7) == 0 || (ft_strncmp(txt, "setenv",
				7) == 0))
		export(env, input + 1);
	else if (ft_strncmp(txt, "unset", 6) == 0 || (ft_strncmp(txt, "unsetenv",
				9) == 0))
		unset(env, input + 1);
	else if (ft_strncmp(txt, "env", 4) == 0)
		display_env(*env);
	else if (ft_strncmp(txt, "cd", 3) == 0)
		set_new_directory(directory, input[1], env);
	else if ((sep->file_in && sep->file_out) || sep->file_out)
		exec_redir_in_child(sep, find_path(txt, *env), input, *env);
	else if (sep->file_in && !sep->file_out)
		exec_redir_in(sep, find_path(txt, *env), input, *env);
	else
		execve_to_child(find_path(txt, *env), input, *env);
	free(txt);
}

int	get_pipe_nbr(t_exec *to_run)
{
	int	res;

	res = 0;
	while (ft_strncmp(to_run->separator->pipe, "|", 1) == 0)
	{
		res += 1;
		to_run = to_run->next;
	}
	return (res);
}

t_exec	*execute_pipe(t_exec *to_run, char **directory, char ***env)
{
	int		*fd;
	pid_t	pid;
	int		i;
	int		j;
	int		count;

	count = get_pipe_nbr(to_run) + 1;
	fd = malloc(count * 2 * sizeof(int));
	if (!fd)
		exit(1);
	i = 0;
	while (i < count)
	{
		if (pipe(fd + i * 2) == -1)
		{
			perror("fork");
			exit(1);
		}
		i += 1;
	}
	i = 0;
	while (i < count)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (pid == 0)
		{
			if (i < count - 1)
				dup2(fd[i * 2 + 1], STDOUT_FILENO);
			if (i > 0)
				dup2(fd[i * 2 - 2], STDIN_FILENO);
			j = -1;
			while (++j < count * 2)
				close(fd[j]);
			execute(to_run->separator->arg, directory, env, to_run->separator);
			exit(EXIT_FAILURE);
		}
		i += 1;
		to_run = to_run->next;
	}
	j = -1;
	while (++j < count * 2)
		close(fd[j]);
	j = -1;
	while (++j < count * 2)
		waitpid(pid, NULL, 0);
	return (to_run);
}

void	execute_all(t_exec *to_run, char **directory, char ***env)
{
	while (to_run)
	{
		if (to_run->separator->pipe == NULL)
			execute(to_run->separator->arg, directory, env, to_run->separator);
		else if (ft_strncmp(to_run->separator->pipe, "|", 1) == 0)
		{
			if (to_run->next)
				to_run = execute_pipe(to_run, directory, env);
			else
				execute(to_run->separator->arg, directory, env,
					to_run->separator);
		}
		else
			execute(to_run->separator->arg, directory, env, to_run->separator);
		if (to_run)
			to_run = to_run->next;
	}
}
