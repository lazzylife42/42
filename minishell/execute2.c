/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:39:37 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/26 12:30:05 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	child_process(t_sep *sep, char **directory, char ***env)
// {
// 	pid_t	pid;
// 	int		fd[2];

// 	if(pipe(fd) == -1)
// 		shell_exit(1, "failed to pipe.\n");
// 	pid = fork();
// 	if (pid == -1)
// 		shell_exit(1, "failed to fork.\n");
// 	if ( pid == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		execute(sep->arg, directory, env, sep);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[1], STDIN_FILENO);
// 		waitpid(pid, NULL, 0);
// 	}
// }

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		shell_exit(1, "failed to open file.\n");
	return (file);
}

int	count_exec(t_exec *to_run)
{
	int count;

	count = 0;
	while (to_run)
	{
		printf("count : %d\n", count);
		count++;
		to_run = to_run->next;
	}
	return (count);
}

void child_process(t_sep *sep, char **directory, char ***env)
{
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1)
        shell_exit(1, "failed to pipe.\n");
    pid = fork();
    if (pid == -1)
        shell_exit(1, "failed to fork.\n");
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execute(sep->arg, directory, env, sep);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

void execute_pipe(t_exec *to_run, char **directory, char ***env)
{
    int i;
	int	file_in;
	int
    int count;

    count = count_exec(to_run);
    if (ft_strncmp(to_run->separator->rd_in, "<<", 3) == 0)
    {
        i = 3;
        printf("Herdoc found!\n");
    }
    else
    {
        i = 2;
        file_out = open_file(to_run->separator->arg[0], 1);
        file_in = open_file(to_run->next->separator->arg[0], 2);
        dup2(file_out, STDOUT_FILENO);
    }
    while (i < count - 2)
    {
        child_process(to_run->separator, directory, env);
        i++;
        to_run = to_run->next;
    }
    dup2(file_in, STDIN_FILENO);
    execute(to_run->separator->arg, directory, env, to_run->separator);
}


