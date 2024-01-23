/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:49:59 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/23 15:54:14 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(int **fd, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		close((*fd)[i]);
		i += 1;
	}
}

void	pipe_init(t_exec *to_run, int *count, int **fd)
{
	int	i;

	*count = 0;
	while (ft_strncmp(to_run->separator->pipe, "|", 1) == 0)
	{
		if (to_run->next != NULL)
		{
			*count += 1;
			to_run = to_run->next;
		}
		else
			break ;
	}
	*count += 1;
	*fd = malloc(*count * 2 * sizeof(int));
	if (!*fd)
		shell_exit(1, NULL);
	i = -1;
	while (++i < *count)
		if (pipe(*fd + i * 2) == -1)
			shell_exit(1, "fork");
}

void	wait_for_child(int **fd, pid_t pid, int n)
{
	int	i;

	i = -1;
	close_fd(fd, n);
	while (++i < n)
		waitpid(pid, NULL, 0);
}

void	set_and_close(int i, int count, int	**fd)
{
	if (i < count - 1)
		dup2((*fd)[i * 2 + 1], STDOUT_FILENO);
	if (i > 0)
		dup2((*fd)[i * 2 - 2], STDIN_FILENO);
	close_fd(fd, count * 2);
}

t_exec	*execute_pipe(t_exec *to_run, char **directory, char ***env)
{
	int		*fd;
	pid_t	pid;
	int		i;
	int		count;

	pipe_init(to_run, &count, &fd);
	i = -1;
	while (++i < count)
	{
		pid = fork();
		if (pid == -1)
			shell_exit(1, RED"fork"RST);
		if (pid == 0)
		{
			set_and_close(i, count, &fd);
			if ((to_run->separator->file_out)
				&& (handle_outfile(to_run->separator)))
				perror(RED"Error handleling outfile"RST);
			execute(to_run->separator->arg, directory, env, to_run->separator);
			exit(EXIT_FAILURE);
		}
		if (i != count - 1)
			waitpid(pid, NULL, 0);
		to_run = to_run->next;
	}
	wait_for_child(&fd, pid, count * 2);
	return (to_run);
}
