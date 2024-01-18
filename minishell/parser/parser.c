/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:49:32 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/18 10:37:52 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*char	*get_file(char **tokens, int index)
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
			if (tokens[index + 1] != NULL)
				return (tokens[index + 1]);
		}
	}
	return (NULL);
}*/

char	*path_test(char *str, char *argv)
{
	char	*path_tmp;
	char	*path;

	if (argv)
	{
		path_tmp = ft_strjoin(str, "/");
		path = ft_strjoin(path_tmp, argv);
		free(path_tmp);
		return (path);
	}
	return (NULL);
}

char	*find_path(char *argv, char **env)
{
	int		i;
	char	**split;
	char	*path;

	if (argv == NULL || env == NULL || env[0] == NULL)
		return (NULL);
	if (access(argv, X_OK) == 0)
		return (ft_strdup(argv));
	i = -1;
	while (ft_strncmp(env[++i], "PATH=", 5) != 0)
		if (env[i + 1] == NULL)
			return (NULL);
	split = ft_split(env[i] + 5, ':');
	i = -1;
	while (split[++i])
	{
		path = path_test(split[i], argv);
		if (access(path, X_OK) == 0)
			return (free_double_str(split), path);
		free(path);
	}
	free_double_str(split);
	return (NULL);
}

char	**parse_arg(char **tokens, int pos)
{
	int		i;
	int		count;
	char	**args;

	i = pos;
	count = 1;
	while (tokens[i + 1] && !is_separator(tokens[i + 1])
		&& !is_redir(tokens[i + 1]))
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

int	count_tok(char **input)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (input[++i])
		count++;
	return (count);
}

t_exec	*parse(t_exec *to_run, char **tk)
{
	int		i;
	int		j;
	t_sep	*n_sep;

	i = -1;
	j = 0;
	while (tk[++i])
	{
		if (is_separator(tk[i]))
		{
			n_sep = create_sep_node(parse_arg(tk, j
						+ (ft_strncmp(tk[j], "<", 1) == 0 * 2)), tk, tk[i], j);
			to_run = add_to_exec_list(to_run, n_sep);
			j = i + 1;
		}
		else if (i == count_tok(tk) - 1)
		{
			n_sep = create_sep_node(parse_arg(tk, j
						+ (ft_strncmp(tk[j], "<", 1) == 0 * 2)), tk, NULL, j);
			to_run = add_to_exec_list(to_run, n_sep);
			break ;
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
