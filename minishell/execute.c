/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:24:49 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/22 11:57:42 by nreichel         ###   ########.fr       */
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
	if (pid == 0)
		execve(pathname, argv, env);
	else
		waitpid(pid, NULL, 0);
}

void	execute(char **input, char **directory, char ***env)
{
	char	*txt;

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
	else
		execve_to_child(find_path(txt, *env), input, *env);
	free(txt);
}

/*int	execute_pipe(t_sep *cmd1, t_sep *cmd2, char **directory, char ***env)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execute(cmd1->arg, directory, env);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipefd[1]);
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("fork");
			return (-1);
		}
		if (pid2 == 0)
		{
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			execute(cmd2->arg, directory, env);
			exit(EXIT_FAILURE);
		}
		else
		{
			close(pipefd[0]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
	return (0);
}*/

int get_pipe_nbr(t_exec *to_run)
{
	int	res;

	res = 0;
	while (ft_strncmp(to_run->separator->pipe->symbol, "|", 1) == 0)
	{
		res += 1;
		to_run = to_run->next;
	}
	return (res);
}

t_exec *execute_pipe(t_exec *to_run, char **directory, char ***env)
{
	int		*fd;
	pid_t	pid;
	int		i;
	int		j;
	int		count;

	count = get_pipe_nbr(to_run) + 1;
	fd = malloc(count * 2 * sizeof (int));
	if (!fd)
		exit(1);
	i = 0;
	while(i < count)
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
			execute(to_run->separator->arg, directory, env);
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
		if (to_run->separator->pipe->symbol == NULL)
			execute(to_run->separator->arg, directory, env);
		else if (ft_strncmp(to_run->separator->pipe->symbol, "|", 1) == 0)
		{
			if (to_run->next)
				to_run = execute_pipe(to_run, directory, env);
			else
				execute(to_run->separator->arg, directory, env);
		}
		if (to_run)
			to_run = to_run->next;
	}
}
