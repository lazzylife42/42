/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:48:04 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/20 14:51:59 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_builtin(char *tok)
{
	if (ft_strncmp(tok, "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(tok, "export", 7) == 0
		|| (ft_strncmp(tok, "setenv", 7) == 0))
		return (1);
	else if (ft_strncmp(tok, "unset", 6) == 0
		|| (ft_strncmp(tok, "unsetenv", 9) == 0))
		return (1);
	return (0);
}

int	is_cmd(char *token, char **env)
{
	char	*path;

	path = find_path(token, env);
	if (path || is_builtin(token))
	{
		free(path);
		return (1);
	}
	return (0);
}

int	is_separator(char *token)
{
	return (ft_strncmp(token, "<", 1) == 0 || ft_strncmp(token, ">", 1) == 0
		|| ft_strncmp(token, "|", 1) == 0);
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

int	count_cmd(char **tokens, char **env)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (is_cmd(tokens[i], env))
			count++;
		i++;
	}
	return (count);
}
