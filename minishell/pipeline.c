/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:54:59 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/26 14:28:20 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count(char ***cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

int	count_pipe(t_exec *to_run)
{
	int i;

	i = 0;
	while (to_run)
	{
		i++;
		to_run = to_run->next;
	}
	return (i);
}

void	pipeline(/*char ***cmd,*/t_exec *to_run, char **directory, char ***env, t_sep *sep)
{
	int i, j = 0;
	pid_t pid;
	int cmd_len = count_pipe(to_run);
	int fd[2 * cmd_len];

	// pipe(2) for cmd_len times
	for (i = 0; i < cmd_len; i++)
	{
		if (pipe(fd + i * 2) < 0)
		{
			perror("couldn't pipe");
			exit(EXIT_FAILURE);
		}
	}
	while (/**cmd != NULL*/to_run)
	{
		if ((pid = fork()) == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			// if there is next
			if (/**(cmd + 1) != NULL*/to_run->next)
			{
				if (dup2(fd[j + 1], 1) < 0)
				{
					perror("dup2");
					exit(EXIT_FAILURE);
				}
			}
			// if there is previous
			if (j != 0)
			{
				if (dup2(fd[j - 2], 0) < 0)
				{
					perror("dup2");
					exit(EXIT_FAILURE);
				}
			}

			for (i = 0; i < 2 * cmd_len; i++)
			{
				close(fd[i]);
			}

			execute(to_run->separator->arg, directory, env, sep);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}

		// no wait in each process,
		// because I want children to exec without waiting for each other
		// as bash does.
		/*cmd++;*/to_run = to_run->next;
		j += 2;
	}
	// close fds in parent process
	for (i = 0; i < 2 * cmd_len; i++)
	{
		close(fd[i]);
	}
	// wait for children
	for (i = 0; i < cmd_len; i++)
		wait(NULL);
}
