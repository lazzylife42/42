/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:54:59 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/26 13:01:10 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	count(char ***cmd)
// {
// 	int	i;

// 	i = 0;
// 	while (cmd[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// void	pipeline(char ***cmd)
// {
// 	int		i = 0, j;
// 	pid_t	pid;
// 	int		cmd_len;
// 	int		fd[2 * cmd_len];

// 	i = 0, j = 0;
// 	cmd_len = count(cmd);
// 	// pipe(2) for cmd_len times
// 	while (i < cmd_len)
// 	{
// 		if (pipe(fd + i * 2) < 0)
// 		{
// 			perror("couldn't pipe");
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// 	while (*cmd != NULL)
// 	{
// 		if ((pid = fork()) == -1)
// 		{
// 			perror("fork");
// 			exit(1);
// 		}
// 		else if (pid == 0)
// 		{
// 			// if there is next
// 			if (*(cmd + 1) != NULL)
// 			{
// 				if (dup2(fd[j + 1], 1) < 0)
// 				{
// 					perror("dup2");
// 					exit(EXIT_FAILURE);
// 				}
// 			}
// 			// if there is previous
// 			if (j != 0)
// 			{
// 				if (dup2(fd[j - 2], 0) < 0)
// 				{
// 					perror("dup2");
// 					exit(EXIT_FAILURE);
// 				}
// 			}
// 			i = 0;
// 			while (i < 2 * cmd_len)
// 			{
// 				close(fd[i]);
// 				i++;
// 			}

// 			// if (execvp((*cmd)[0], *cmd) < 0)
// 			// {
// 			// 	perror((*cmd)[0]);
// 			// 	exit(EXIT_FAILURE);
// 			// }
// 		}
// 		else if (pid < 0)
// 		{
// 			perror("error");
// 			exit(EXIT_FAILURE);
// 		}
// 		// no wait in each process,
// 		// because I want children to exec without waiting for each other
// 		// as bash does.
// 		cmd++;
// 		j += 2;
// 	}
// 	// close fds in parent process
// 	i = 0;
// 	while (i < 2 * cmd_len)
// 	{
// 		close(fd[i]);
// 		i++;
// 	}
// 	// wait for children
// 	i = 0;
// 	while (i < cmd_len)
// 	{
// 		wait(NULL);
// 		i++;
// 	}
// }

void	pipeline(t_exec *to_run, char **directory, char ***env)
{
	t_exec	*current_exec;
	t_sep	*sep;
	pid_t	pid;
	int		cmd_len;
	int		fd[2 * cmd_len];
	char	***cmd;

	current_exec = to_run;
	int i, j = 0;
	while (current_exec != NULL)
	{
		sep = current_exec->separator;
		cmd_len = count(sep->arg);
		// pipe(2) for cmd_len times
		i = 0;
		while (i < cmd_len)
		{
			if (pipe(fd + i * 2) < 0)
			{
				perror("couldn't pipe");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		cmd = sep->arg;
		while (*cmd != NULL)
		{
			if ((pid = fork()) == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				// if there is next
				if (*(cmd + 1) != NULL)
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
				i = 0;
				while (i < 2 * cmd_len)
				{
					close(fd[i]);
					i++;
				}
				execute(*cmd, directory, env, sep);
				// If exec fails
				perror("exec");
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("error");
				exit(EXIT_FAILURE);
			}
			cmd++;
			j += 2;
		}
		// close fds in parent process
		i = 0;
		while (i < 2 * cmd_len)
		{
			close(fd[i]);
			i++;
		}
		// wait for children
		i = 0;
		while (i < cmd_len)
		{
			wait(NULL);
			i++;
		}
		current_exec = current_exec->next;
	}
}
