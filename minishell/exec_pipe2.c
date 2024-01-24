/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:58:40 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:44 by nreichel         ###   ########.fr       */
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

void	wait_for_child(int **fd, pid_t pid, int n, char ***env)
{
	int	i;
	int	status;

	i = -1;
	close_fd(fd, n);
	while (++i < n)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			set_dollar(env, WEXITSTATUS(status));
		else
			set_dollar(env, 1);
	}
}

void	set_and_close(int i, int count, int	**fd)
{
	if (i < count - 1)
		dup2((*fd)[i * 2 + 1], STDOUT_FILENO);
	if (i > 0)
		dup2((*fd)[i * 2 - 2], STDIN_FILENO);
	close_fd(fd, count * 2);
}

void	pipe_next(int i, int count, pid_t pid, t_exec **to_run)
{
	if (i != count - 1)
		waitpid(pid, NULL, 0);
	*to_run = (*to_run)->next;
}
