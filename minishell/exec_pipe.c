/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:49:59 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/24 09:54:32 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_check(t_exec *to_run)
{
	if ((to_run->separator->file_out)
		&& (handle_outfile(to_run->separator)))
		perror(RED "Error handleling outfile" RST);
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
			shell_exit(1, "fork");
		if (pid == 0)
		{
			set_and_close(i, count, &fd);
			error_check(to_run);
			execute(to_run->separator->arg, directory, env, to_run->separator);
			exit(ft_atoi(check_env(*env, "?", 1)));
		}
		if (i != count - 1 && !ft_strncmp(to_run->separator->arg[0], "cat", 3))
			waitpid(pid, NULL, 0);
		to_run = to_run->next;
	}
	wait_for_child(&fd, pid, count * 2, env);
	return (to_run);
}
