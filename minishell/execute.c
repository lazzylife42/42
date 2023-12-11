/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:09:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/11 23:30:42 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef enum
{
	REDIRECT_OUT,    // >
	REDIRECT_APPEND, // >>
	REDIRECT_IN,     // <
	PIPE,            // |
	NEXT,
	UNDEF,
}		t_operator;

int	is_next_op(char **input, int pos)
{
	if (input[pos + 1])
	{
		if (ft_strncmp(input[pos + 1], ">>", 2) == 0)
			return (REDIRECT_APPEND);
		else if (ft_strncmp(input[pos + 1], ">", 1) == 0)
			return (REDIRECT_OUT);
		else if (ft_strncmp(input[pos + 1], "<", 1) == 0)
			return (REDIRECT_IN);
		else if (ft_strncmp(input[pos + 1], "|", 1) == 0)
			return (PIPE);
	}
	return (-1);
}

int	exec_cmd(char **input, char **env)
{
	int			i;
	int			id;
	int			fd[2];
	t_operator	operator;

	i = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "pwd", 4) == 0 || ft_strncmp(input[i], "echo",
				5) == 0 || ft_strncmp(input[i], "cd", 3) == 0)
				i++;
		else
		{
			if (is_next_op(input, i) !=  -1)
			{
				pipe(fd);
				id = fork();
				if (id == 0)
				{
					operator = is_next_op(input, i);
					if (operator == REDIRECT_OUT)
						execute_redir_out(input[i], input[i + 2], env);
					else if (operator == REDIRECT_APPEND)
						execute_redir_append(input[i], input[i + 2], env);
					else if (operator == REDIRECT_IN)
						execute_redir_in(input[i], input[i + 2], env);
					else if (operator == PIPE)
						execute_pipe(input[i], input[i + 2], env);
					else
						execute(input[i], env);
				}
				else
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
	int i;
	char **split;
	char *path;
	char *path_tmp;

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