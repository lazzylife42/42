/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:49:32 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/20 14:52:51 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_file(char **tokens, int index)
{
	if (index >= 0)
	{
		if (tokens == NULL || tokens[index] == NULL)
			return (NULL);
		if (ft_strncmp(tokens[index], ">", 1) == 0)
		{
			if (tokens[index + 1] != NULL)
				return (tokens[index + 1]);
		}
		else if (ft_strncmp(tokens[index], "<", 1) == 0)
		{
			if (index >= 1 && tokens[index - 1] != NULL)
				return (tokens[index - 1]);
		}
	}
	return (NULL);
}

char	*find_path(char *argv, char **env)
{
	int		i;
	char	**split;
	char	*path;
	char	*path_tmp;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	split = ft_split(env[i] + 5, ':');
	i = 0;
	while (split[i])
	{
		path_tmp = ft_strjoin(split[i], "/");
		path = ft_strjoin(path_tmp, argv);
		free(path_tmp);
		if (access(path, X_OK) == 0)
		{
			ft_free_split(split);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_split(split);
	return (NULL);
}

char	**parse_arg(char **tokens, char **env, int pos)
{
	int		i;
	int		count;
	char	**args;

	i = pos;
	count = 1;
	while (tokens[i + 1] && !is_separator(tokens[i + 1]) && !is_cmd(tokens[i
				+ 1], env))
	{
		count++;
		i++;
	}
	args = (char **)malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (count > 0)
	{
		args[i++] = ft_strdup(tokens[pos++]);
		count--;
	}
	args[i] = NULL;
	return (args);
}

t_exec	*parse(t_exec *to_run, char **tokens, char **env)
{
	int		i;
	int		j;
	t_sep	*new_sep;

	i = -1;
	while (tokens[++i])
	{
		if (is_cmd(tokens[i], env))
		{
			j = i;
			while (tokens[j] && !is_separator(tokens[j]))
				j++;
			if (tokens[j] && is_separator(tokens[j]))
				new_sep = create_sep_node(parse_arg(tokens, env, i),
						ft_strdup(tokens[j]), get_file(tokens, j));
			else
			{
				new_sep = create_sep_node(parse_arg(tokens, env, i), NULL,
						get_file(tokens, i - 1));
				j -= 1;
			}
			to_run = add_to_exec_list(to_run, new_sep);
			i = j;
		}
	}
	return (to_run);
}
/*
int	main(int ac, char **av, char **env)
{
	t_exec	*to_run = NULL;
	(void)ac;

	to_run = parse(to_run, (av + 1), env);
	print_to_run(to_run);
	free_exec_list(to_run);
	return (0);
}*/
