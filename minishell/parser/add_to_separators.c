/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_separators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:55:36 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/14 15:26:05 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_cmd(t_sep *operator, char ** token, int pos)
{
	if (ft_strncmp(token[pos], "|", 1) == 0 || ft_strncmp(token[pos], "<",
			1) == 0 || ft_strncmp(token[pos], ">", 1) == 0)
	{
		if (is_arg(token[pos - 1]))
		{
			operator->cmd = token[pos - 2];
			operator->arg = token[pos - 1];
		}
		else
		{
			operator->cmd = token[pos - 1];
			operator->arg = NULL;
		}
	}
}

t_exec	*add_operator(t_exec *separator, char **token, int pos)
{
	t_pipe	*symbol;

	t_sep *operator=(t_sep *) malloc(sizeof(t_sep));
	symbol = (t_pipe *)malloc(sizeof(t_pipe));
	symbol->pipe = token[pos];
	if (ft_strncmp(token[pos], "<", 1) == 0)
	{
		symbol->file = token[pos - 1];
	}
	else if (ft_strncmp(token[pos], ">", 1) == 0)
	{
		symbol->file = token[pos + 1];
	}
	else if (ft_strncmp(token[pos], "|", 1) == 0)
	{
		symbol->file = NULL;
	}
	operator->pipe = symbol;
	add_cmd(operator, token, pos);
	return (separator);
}

t_exec	*add_operator_to_exec(t_exec *separators, char **token, int pos)
{
	t_pipe	*symbol;
	t_exec	*new_node;
	t_exec	*current;

	t_sep *operator=(t_sep *) malloc(sizeof(t_sep));
	symbol = (t_pipe *)malloc(sizeof(t_pipe));
	symbol->pipe = token[pos];
	if (ft_strncmp(token[pos], "<", 1) == 0)
		symbol->file = token[pos - 1];
	else if (ft_strncmp(token[pos], ">", 1) == 0)
		symbol->file = token[pos + 1];
	else if (ft_strncmp(token[pos], "|", 1) == 0)
		symbol->file = NULL;
	operator->pipe = symbol;
	add_cmd(operator, token, pos);
	new_node = (t_exec *)malloc(sizeof(t_exec));
	new_node->separators = operator;
	new_node->next = NULL;
	if (separators == NULL)
		separators = new_node;
	else
	{
		current = separators;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (separators);
}

void	print_separator(t_exec *separators)
{
	t_sep	*current_sep;

	while (separators != NULL)
	{
		current_sep = separators->separators;
		while (current_sep != NULL)
		{
			printf("Commande: %s\n", current_sep->cmd);
			printf("Argument: %s\n", current_sep->arg);
			if (current_sep->pipe != NULL)
			{
				printf("Pipe: %s\n", current_sep->pipe->pipe);
				printf("Fichier: %s\n\n", current_sep->pipe->file);
			}
			current_sep = current_sep->pipe;
		}
		separators = separators->next;
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
