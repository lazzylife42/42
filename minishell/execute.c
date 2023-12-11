/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:09:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/11 21:02:55 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef enum  
{
	REDIRECT_OUT,   // >
	REDIRECT_APPEND,// >>
	REDIRECT_IN,    // <
	PIPE,           // |
	NEXT,
	UNDEF,
}	t_operator;

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
int	find_operator(char **input)
{
	static int i;

	i = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "> ", 2) == 0)
			return (REDIRECT_OUT);
		else if (ft_strncmp(input[i], ">>", 2) == 0)
			return (REDIRECT_APPEND);
		else if (ft_strncmp(input[i], "< ", 2) == 0)
			return (REDIRECT_IN);
		else if (ft_strncmp(input[i], "| ", 2) == 0)
			return (PIPE);
		else
			return(NEXT);
		i++;
	}
	return (0);
}

int exec_cmd(char **input, char **env)
{
	int			i = 0;
	int			fd[2];
	pid_t		pid;
	t_operator	operator;

	while (input[i])
	{
		if (ft_strncmp(input[i], "pwd", 4) == 0
			|| ft_strncmp(input[i], "echo", 5) == 0
			|| ft_strncmp(input[i], "cd", 3) == 0)
			{
		}
		else
		{
			operator = find_operator(input + i);
			if (operator == REDIRECT_OUT)
			{
				printf(">\n");
			}
			else if (operator == REDIRECT_APPEND)
			{
				printf(">>\n");	
			}
			else if (operator == REDIRECT_IN)
			{
				printf("<\n");
			}
			else if (operator == PIPE)
			{
				printf("coucou\n");
				execute_pipe(&input[i], &input[i + 2], env);
			}
			else
			{
				pid = fork();
				if (pid == 0)
					execute(input[i], env);
				else if (pid > 0)
					wait(NULL);
			}
		}
		i++;
	}
	return (1);
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