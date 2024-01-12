/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:24:49 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/12 15:14:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execve_to_child(char *pathname, char **argv, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid != 0)
	{
		sigactive(-1);
		waitpid(pid, NULL, 0);
		sigactive(1);
	}
	else
		execve(pathname, argv, env);
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
/*
void	exec_redir_out(t_pipe *pip, char *pathname, char **argv, char **env)
{
	pid_t	pid;
	int		fd;
	char	*path;
	char	*str;

	if (strncmp(pip->symbol, ">>", 2) == 0)
	{
		if ((fd = open(pip->file, O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
			exit(EXIT_FAILURE);
	}
	else if (strncmp(pip->symbol, ">", 1) == 0)
	{
		if ((fd = open(pip->file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
			exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execve(pathname, argv, env);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}*/

void	set_env_bs(char ***env, char *txt)
{
	char	*path;
	char	*str;
	
	path = find_path(txt, *env);
	if (path)
		str = ft_strjoin("_=", path);
	else
		str = ft_strjoin("_=", txt);
	if (!str)
		exit(1);
	export_one(env, str);
	free(str);
}

void	execute(char **input, char **directory, char ***env, t_sep *sep)
{
	char	*txt;
	char	*path;

	txt = translate_quote(input[0], *env);
	if (ft_strncmp(txt, "echo", 5) == 0)
		echo(input + 1, env);
	else if (ft_strncmp(txt, "pwd", 4) == 0)
		printf("%s\n", *directory);
	else if (ft_strncmp(txt, "exit", 5) == 0)
		exit(1);
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
	{
		path = find_path(txt, *env);
		printf("%s\n", path);
		if (path)
			execve_to_child(path, input, *env);
	}
	free(txt);
}

int	get_pipe_nbr(t_exec *to_run)
{
	int	res;

	res = 0;
	while (ft_strncmp(to_run->separator->pipe, "|", 1) == 0)
	{
		// if (ft_strncmp(to_run->separator->rd_out, ">", 1) == 0)
		// 	res++;
		res += 1;
		to_run = to_run->next;
	}
	return (res);
}

void close_fd(int **fd, int pipe_nbr)
{
	int i = -1;
	
    while (++i < pipe_nbr)
    {
        close(fd[i][0]); // Close read end
        close(fd[i][1]); // Close write end
    }
}

t_exec	*exec_pipe(t_exec *to_run, char **directory, char ***env)
{
    int	**fd;
    int	i;
    int	pid;
    int	pid1;
    int	pipe_nbr;

    pipe_nbr = get_pipe_nbr(to_run) + 1;
    fd = malloc(pipe_nbr * sizeof(int *));
    i = 0;
    while (i < pipe_nbr)
    {
        fd[i] = malloc(2 * sizeof(int));
        if (pipe(fd[i]) == -1)
            exit(EXIT_FAILURE);
        i++;
    }
    pid = fork();
    i = 0;
    if (pid == -1)
        exit(EXIT_FAILURE);
    else if (pid == 0)
    {
        dup2(fd[i][1], STDOUT_FILENO);
        close_fd(fd, pipe_nbr);
        execute(to_run->separator->arg, directory, env, to_run->separator);
    }
    waitpid(pid, NULL, 0);
	i = -1;
    while (++i < pipe_nbr)
    {
        pid1 = fork();
        if (pid1 == -1)
            exit(EXIT_FAILURE);
        else if (pid1 == 0)
        {
            // Child process
            if (i > 0)
            {
                // Duplicate standard input from the previous pipe
                dup2(fd[i - 1][0], STDIN_FILENO);
                close_fd(fd, pipe_nbr); // Close unused file descriptors
            }
            if (i < pipe_nbr - 1)
            {
                // Duplicate standard output to the next pipe
                dup2(fd[i][1], STDOUT_FILENO);
                close_fd(fd, pipe_nbr); // Close unused file descriptors
            }
            to_run = to_run->next;
            execute(to_run->separator->arg, directory, env, to_run->separator);
        }
        if (i < pipe_nbr - 1)
            close(fd[i][1]); // Close the write end of the current pipe
        else
            close_fd(fd, pipe_nbr); // Close file descriptors for the last command
        waitpid(pid1, NULL, 0);
        to_run = to_run->next;
    }
    i = 0;
    while (i < pipe_nbr)
    {
        free(fd[i]);
        i++;
    }
    free(fd);
    return to_run;
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

void execute_all(t_exec *to_run, char **directory, char ***env)
{
    while (to_run)
    {
        if (to_run->separator->pipe == NULL)
            execute(to_run->separator->arg, directory, env, to_run->separator);
        else if (ft_strncmp(to_run->separator->pipe, "|", 1) == 0)
        {
            if (to_run->next)
                to_run = exec_pipe(to_run, directory, env);
            else
                execute(to_run->separator->arg, directory, env, to_run->separator);
        }
        else
            execute(to_run->separator->arg, directory, env, to_run->separator);
        if (to_run && to_run->next)
            to_run = to_run->next;
        else
            break;
    }
}

