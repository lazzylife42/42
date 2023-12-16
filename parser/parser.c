/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:49:32 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/16 01:02:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_separator(char *token)
{
	return (ft_strncmp(token, "<", 1) == 0 || ft_strncmp(token, ">", 1) == 0
		|| ft_strncmp(token, "|", 1) == 0 || ft_strncmp(token, ";", 1) == 0);
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
int	is_semicon(char *token)
{
	return (ft_strncmp(token, ";", 1) == 0);
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
		return (NULL);
	if (ft_strncmp(tokens[index], ">", 1) == 0 || ft_strncmp(tokens[index], "<",
			1) == 0)
	{
		if (tokens[index + 1] != NULL)
			return (tokens[index + 1]);
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
		free(path_tmp);
		// printf("PATH:%s\n", path);
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

char	**parse_arg(char **tokens, int pos, int offset)
{
	int		i;
	char	**args;

	i = 0;
	if (offset == 0)
		return (NULL);
	args = (char **)malloc(sizeof(char *) * (offset + 1));
	if (args == NULL)
		return (NULL);
	while (offset > 0)
	{
		args[i] = ft_strdup(tokens[pos]);
		if (args[i] == NULL)
			return (NULL);
		i++;
		pos++;
		offset--;
	}
	args[i] = NULL;
	return (args);
}

int	find_cmd_offset(char **tokens, int current_index, char **env)
{
	int	offset;

	offset = 0;
	while (current_index > 0 && !is_cmd(tokens[current_index], env))
	{
		current_index--;
		offset++;
	}
	if (is_cmd(tokens[current_index], env))
		return (offset);
	else
	{
		printf("path not found !\n");
		printf("Stopped at \"%s\"\n", tokens[current_index]);
		exit(EXIT_FAILURE);
	}
	return (-1);
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
				offset = find_cmd_offset(tokens, i, env);
				new_sep = create_sep_node(tokens[i - offset], parse_arg(tokens - offset + 1, i, offset - 1), tokens[i], file);
				i += offset + 1;
			}
			else if (is_semicon(tokens[i]))
			{
				new_sep = create_sep_node(NULL, NULL, tokens[i], NULL);
				i++;
			}
			else
			{
				offset = find_cmd_offset(tokens, i, env);
				new_sep = create_sep_node(tokens[i - offset], parse_arg(tokens - offset + 1, i, offset - 1), tokens[i], NULL);
				i += offset + 1;
			}
			to_run = add_to_exec_list(to_run, new_sep);
		}
	}
	offset = find_cmd_offset(tokens, i, env);
	// new_sep = create_sep_node(tokens[i - offset], parse_arg(tokens - offset + 1, i, offset - 1), NULL, NULL);
	return (add_to_exec_list(to_run, new_sep));
}

void	print_to_run(t_exec *to_run)
{
	t_sep	*current_sep;
	int		i;
	char	**args;

	if (to_run == NULL)
	{
		printf("Nothing to execute...\n");
		return ;
	}
	while (to_run != NULL)
	{
		i = 0;
		current_sep = to_run->separator;
		if (current_sep != NULL)
		{
			if (current_sep->cmd != NULL)
				printf("Command :  [%s]\n", current_sep->cmd);
			else
				printf("Command is [null]\n");
			if (current_sep->arg != NULL)
			{
				args = current_sep->arg;
				while (args[i] != NULL)
				{
					printf("Argument:  [%s]\n", args[i]);
					i++;
				}
			}
			else
			{
				printf("Argument:  [null]\n");
			}
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
