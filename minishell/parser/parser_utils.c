/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:48:04 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/26 21:45:00 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_separator(char *token)
{
	return (ft_strncmp(token, "|", 1) == 0);
}

int	is_redir(char *token)
{
	return (ft_strncmp(token, "<", 1) == 0 || ft_strncmp(token, ">", 1) == 0);
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

t_sep	*create(char **tk, int index, char *separator, int j)
{
	int	offset;

	offset = 0;
	if (tk[index][0] == '|')
	{
		if (ft_strncmp(tk[j], "<", 2) == 0)
			return (create_sep_node(parse_arg(tk, j + 2), tk, tk[index], j));
		else
			return (create_sep_node(parse_arg(tk, j), tk, separator, j));
	}
	else
	{
		if (ft_strncmp(tk[j], "<", 2) == 0)
		{
			while (ft_strncmp(tk[j + offset], "<", 2) == 0 && tk[j + offset
					+ 2])
				offset += 2;
			return (create_sep_node(parse_arg(tk, j + offset), tk, NULL, j));
		}
		else
			return (create_sep_node(parse_arg(tk, j), tk, NULL, j));
	}
}
