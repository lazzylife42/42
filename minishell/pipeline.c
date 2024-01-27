/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:54:59 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/27 10:16:41 by smonte-e         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (to_run)
	{
		i++;
		to_run = to_run->next;
	}
	return (i);
}
t_exec	*handle_redir(t_exec *to_run)
{
	t_exec	*current;

	current = to_run;
	while (current)
	{
		if (current->separator->file_out)
			handle_outfile(current->separator);
		if (current->separator->file_in)
			handle_infile(current->separator);
		current = current->next;
	}
	return (to_run);
}

void	pipeline(t_exec *to_run, char **directory, char ***env)
{
	pid_t	pid;
	int		cmd_len;
	cmd_len = count_pipe(to_run);
	int		fd[2 * cmd_len];

	int i, j = 0;
	i = -1;
	while (++i < cmd_len)
		if (pipe(fd + i * 2) < 0)
			shell_exit(1, "couldn't pipe");
	while (to_run)
	{
		if ((pid = fork()) == -1)
			shell_exit(1, "fork");
		else if (pid == 0)
		{
			if (to_run->next)
				if (dup2(fd[j + 1], 1) < 0)
					shell_exit(1, "dup2");
			if (j != 0)
				if (dup2(fd[j - 2], 0) < 0)
					shell_exit(1, "dup2");
			i = -1;
			while (++i < 2 * cmd_len - 1)
				close(fd[i]);
			execute(to_run->separator->arg, directory, env, to_run->separator);
			exit(0);
		}
		else if (pid < 0)
			shell_exit(1, "error");
		to_run = to_run->next;
		j += 2;
	}
	i = -1;
	while (++i < 2 * cmd_len)
		close(fd[i]);
	i = -1;
	while (++i < cmd_len)
		wait(NULL);
}
