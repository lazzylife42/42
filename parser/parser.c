/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:49:32 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/15 13:07:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_separator(char *token)
{
	return (ft_strncmp(token, "<", 1) == 0 || ft_strncmp(token, ">", 1) == 0
		|| ft_strncmp(token, "|", 1) == 0);
}

int	is_agrument(char *token)
{
	return (ft_strncmp(token, "-", 1) == 0);
}
int	is_cmd(char *token, char **env)
{
	if (find_path(token, env))
		return (1);
	return (0);
}


int	count_separators(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (is_separator(tokens[i]))
			count++;
		i++;
	}
	return (count);
}

char	*get_redirected_file(char **tokens, int index)
{
	if (tokens == NULL || tokens[index] == NULL)
	{
		return (NULL);
	}
	if (ft_strncmp(tokens[index], ">", 1) == 0 || ft_strncmp(tokens[index], "<",
			1) == 0)
	{
		if (tokens[index + 1] != NULL)
		{
			return (tokens[index + 1]);
		}
	}
	return (NULL);
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
		// printf("PATH :%s\n", path);
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

t_exec	*parse(t_exec *to_run, char **tokens, char **env)
{
	int		i;
	int		offset;
	int		separators;
	char	*file;
	t_sep	*new_sep;

	if (tokens == NULL || tokens[0] == NULL)
		return (NULL);
	separators = count_separators(tokens);
	to_run = (t_exec *)malloc(sizeof(t_exec) * (separators + 1));
	i = -1;
	while (tokens[++i])
	{
		if (is_separator(tokens[i]))
		{
			file = get_redirected_file(tokens, i);
			if (file != NULL)
			{
				new_sep = create_sep_node(tokens[i - 2], tokens[i - 1],
						tokens[i], file);
				i++;
			}
			else
			{
				offset = 0;
				while (!is_cmd(tokens[i - 1], env))
				{
					i--;
					offset++;
					if (offset > i)
					{
						printf("path not found !\n");
						exit(EXIT_FAILURE);
					}
				}
				new_sep = create_sep_node(tokens[i - 1], tokens[i], tokens[i + offset], NULL);
				i += offset;
				// if (is_agrument(tokens[i - 1]))
				// 	new_sep = create_sep_node(tokens[i - 2], tokens[i - 1], tokens[i], NULL);
				// else
				// 	new_sep = create_sep_node(tokens[i - 1], NULL, tokens[i], NULL);
			}
			to_run = add_to_exec_list(to_run, new_sep);
		}
	}
	offset = 0;
	while (!is_cmd(tokens[i - 1], env))
	{
		i--;
		offset++;
		if (offset > i)
		{
			printf("path not found !\n");
			exit(EXIT_FAILURE);
		}
	}
	new_sep = create_sep_node(tokens[i - 1], tokens[i], tokens[i + offset], NULL);
	i += offset;
	// if (is_agrument(tokens[i - 1]))
	// 	new_sep = create_sep_node(tokens[i - 2], tokens[i - 1], tokens[i], NULL);
	// else
	// 	new_sep = create_sep_node(tokens[i - 1], NULL, tokens[i], NULL);
	return (to_run = add_to_exec_list(to_run, new_sep));
}

void	print_to_run(t_exec *to_run)
{
	t_sep	*current_sep;

	if (to_run == NULL)
	{
		printf("Nothing to execute...\n");
		return ;
	}
	while (to_run != NULL)
	{
		current_sep = to_run->separator;
		if (current_sep != NULL)
		{
			if (current_sep->cmd != NULL)
				printf("Command :  [%s]\n", current_sep->cmd);
			else
				printf("Command is [null]\n");
			if (current_sep->arg != NULL)
				printf("Argument:  [%s]\n", current_sep->arg);
			else
				printf("Argument:  [null]\n");
			if (current_sep->pipe != NULL && current_sep->pipe->symbol != NULL)
				printf("Operator:  [%s]\n", current_sep->pipe->symbol);
			else
				printf("Operator:  [null]\n");
			if (current_sep->pipe != NULL && current_sep->pipe->file != NULL)
				printf("File    :  [%s]\n", current_sep->pipe->file);
			else
				printf("File    :  [null]\n");
		}
		printf("---------\n");
		to_run = to_run->next;
	}
}

int	main(int ac, char **av, char **env)
{
	t_exec	*to_run;

	to_run = parse(to_run, (av + 1), env);
	print_to_run(to_run);
	return (0);
}
