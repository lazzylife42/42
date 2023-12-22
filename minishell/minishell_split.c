/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:37:41 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/14 09:57:41 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	next_end(char *str)
{
	int	i;
	int	type;

	i = 0;
	type = (str[0] == '"') * 1 + (str[0] == '\'') * 2;
	if (str[0] == '|')
		return (1);
	if (type != 0)
	{
		while (str[i])
		{
			if ((i > 0) && ((type == 1 && str[i] == '"')
					|| (type == 2 && str[i] == '\'')))
			{
				i += 1;
				break ;
			}
			i += 1;
		}
	}
	else
		while (str[i] && !(str[i] == ' ' || str[i] == '|'))
			i += 1;
	return (i);
}

static char	*return_str(char const *str, int nbr)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(nbr + 1);
	if (!res)
		return (0);
	while (i < nbr)
	{
		res[i] = str[i];
		i += 1;
	}
	res[i] = '\0';
	return (res);
}

char	**ralloc(char **res)
{
	char	**new_res;
	int		len;
	int		i;

	i = 0;
	len = double_str_len(res);
	new_res = malloc((len + 2) * sizeof(char *));
	if (!new_res)
	{
		free_double_str(res);
		return (NULL);
	}
	while (res[i])
	{
		new_res[i] = res[i];
		i += 1;
	}
	new_res[i] = NULL;
	new_res[i + 1] = NULL;
	free(res);
	return (new_res);
}

char	**add_word(char **res, char *str, int end)
{
	if (end <= 0)
		return (res);
	if (res == NULL)
	{
		res = malloc(2 * sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = return_str(str, end);
		if (!res[0])
			exit(1);
		res[1] = NULL;
	}
	else
	{
		res = ralloc(res);
		if (!res)
			return (NULL);
		res[double_str_len(res)] = return_str(str, end);
		if (!res[double_str_len(res) - 1])
			exit(1);
	}
	return (res);
}

char	**minishell_split(char *str)
{
	char	**res;
	int		len;

	res = NULL;
	while (*str)
	{
		while (*str == ' ')
			str += 1;
		len = next_end(str);
		res = add_word(res, str, len);
		if (!res)
			return (NULL);
		str += len;
	}
	return (res);
}