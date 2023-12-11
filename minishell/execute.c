/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:09:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/11 17:14:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int exec_cmd(char **input, char **env)
{
	int 	i = 0;
	pid_t	pid;
	
	while (input[i])
	{
		if (ft_strncmp(input[i], "pwd", 4) == 0
			|| ft_strncmp(input[i], "echo", 5) == 0
			|| ft_strncmp(input[i], "cd", 3) == 0)
			{
		}
		else
		{
			if (ft_strncmp(input[i + 1], "|", 1) == 0)
			{
				pid = fork();
				if (pid == 0)
				{
					child_process(input[i], env);
				}
				else 
				{
					wait(NULL);
				}
			}
		}
		i++;
	}
	return 1;
}

void	execute(char *argv, char **envp)
{
	int		i;
	char	**cmd;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	printf("%s\n", path);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror("Command not found.\n");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("Can't execute the command.\n");
		exit(127);
	}
}

char	*find_path(char *argv, char **envp)
{
	int		i;
	char	**split;
	char	*path;
	char	*path_tmp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	split = ft_split(envp[i] + 5, ':');
	i = 0;
	while (split[i])
	{
		path_tmp = ft_strjoin(split[i], "/");
		path = ft_strjoin(path_tmp, argv);
		free(path_tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	return (NULL);
}