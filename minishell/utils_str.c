/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:27:32 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/11 11:31:47 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	double_str_len(char **str)
{
	int	res;

	res = 0;
	while(str[res])
		res += 1;
	return (res);
}

char	**duplicate_env(char **env)
/* duplicate environment variables*/
{
	int		len;
	int		i;
	char	**res;

	i = 0;
	len = double_str_len(env);
	res = malloc((len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = ft_strdup(env[i]);
		i += 1;
	}
	res[i] = NULL;
	return (res);
}