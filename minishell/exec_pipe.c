/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:49:59 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/18 16:04:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_pipe_nbr(t_exec *to_run)
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
		shell_exit(1);
	i = 0;
	while (i < count)
	{
		if (pipe(fd + i * 2) == -1)
		{
			perror("fork");
			shell_exit(1);
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
			shell_exit(1);
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
			if (to_run->separator->file_out)
				if (handle_outfile(to_run->separator))
					perror(RED "Error handleling outfile" RST);
			execute(to_run->separator->arg, directory, env, to_run->separator);
			shell_exit(EXIT_FAILURE);
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
