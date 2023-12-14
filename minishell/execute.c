/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:09:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/12 12:02:38 by smonte-e         ###   ########.fr       */
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

int	exec_op(char **input, char **env, int *pos)
{
	int			id;
	int			fd[2];
	int			error_occurred;
	t_operator	operator;

	error_occurred = 0;
	pipe(fd);
	id = fork();
	if (id == 0)
	{
		operator= is_next_op(input, *pos);
		if (is_next_op(input, *pos) != -1)
		{
			if (operator== REDIRECT_OUT)
			{
				if (execute_redir_out(input[*pos], input[*pos + 2], env) == -1)
					error_occurred = 1;
			}
			else if (operator== REDIRECT_APPEND)
			{
				if (execute_redir_append(input[*pos], input[*pos + 2], env) ==
					-1)
					error_occurred = 1;
			}
			else if (operator== REDIRECT_IN)
			{
				if (execute_redir_in(input[*pos], input[*pos + 2], env) == -1)
					error_occurred = 1;
			}
			else if (operator== PIPE)
			{
				if (execute_pipe(input[*pos], input[*pos + 2], env) == -1)
					error_occurred = 1;
			}
			pos += 2;
		}
		else
		{
			if (execute(input[*pos], env) == -1)
				error_occurred = 1;
			pos++;
		}
		if (error_occurred)
			return (-1);
	}
	else
		wait(NULL);
	return (0);
}

void	exec_cmd(char **input, char **env)
{
	int	i;
	int	id;
	int	fd[0];

	i = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "pwd", 4) == 0 || ft_strncmp(input[i], "echo",
				5) == 0 || ft_strncmp(input[i], "cd", 3) == 0)
			i++;
		else
		{
			pipe(fd);
			id = fork();
			if (id == 0)
			{
				exec_op(input, env, &i);
				exit(EXIT_SUCCESS);
			}
			else
				wait(NULL);
			i++;
		}
	}
}

int	is_operator(char *token)
{
	return (token[0] == '|' || token[0] == '>' || token[0] == '<');
}

int	execute(char *argv, char **envp)
{
	int		i;
	char	**cmd;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (is_operator(cmd[0]))
	{
		perror("Invalid command.\n");
		return (-1);
	}
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror("Command not found.\n");
		return (-1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("Can't execute the command.\n");
		return (-1);
	}
	return (0);
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
		if (!is_operator(argv))
		{
			path_tmp = ft_strjoin(split[i], "/");
			path = ft_strjoin(path_tmp, argv);
			free(path_tmp);
			if (access(path, X_OK) == 0)
				return (path);
			free(path);
		}
		i++;
	}
	i = -1;
	while (split[++i])
		free(split[i]);
	return (NULL);
}
