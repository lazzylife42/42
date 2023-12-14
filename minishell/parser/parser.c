/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:53:28 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/14 15:23:15 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_operator(char *token)
{
	return (token[0] == '|' || token[0] == '>' || token[0] == '<');
}

int	is_cmd(char *token, char **env)
{
	if (find_path(token, env))
		return (1);
	return (0);
}

int	is_arg(char *token)
{
	if (ft_strncmp(token, "-", 1) == 0)
		return (1);
	return (0);
}

int	count_sep(char **input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (is_operator(input[i]))
			count++;
		i++;
	}
	return (count);
}

t_exec	*parse_separators(char **input, char **env)
{
	int		i;
	int		sep_count;
	t_exec	*separators;

	i = 0;
	sep_count = count_sep(input);
	separators = NULL;
	while (input[i])
	{
		separators = add_operator_to_exec(separators, input, i);
		i++;
	}
	return (separators);
}
