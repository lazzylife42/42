/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:26:32 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/11 09:27:40 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check_env(char **env, char *str, int len)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], str, len) == 0 && env[i][len] == '=')
				return (env[i] + len + 1);
			i += 1;
		}
	}
	return (NULL);
}

void	env_ralloc_del(char ***env, int pos)
{
	char	**res;
	int		i;
	int		off;

	i = 0;
	off = 0;
	res = malloc(double_str_len(*env) * sizeof(char *));
	if (!res)
		return ;
	while ((*env)[i])
	{
		if (i != pos)
			res[i - off] = (*env)[i];
		else
		{
			free((*env)[i]);
			off = 1;
		}
		i += 1;
	}
	res[i - off] = NULL;
	free(*env);
	*env = res;
}

bool	env_var_valid(char *var)
{
	int	step;

	step = 0;
	while (*var && *var != '=')
	{
		if (!(ft_isalpha(*var) || *var == '_'))
		{
			printf("export: '%s': not a valid identifier\n", var);
			return (false);
		}
		var += 1;
		step += 1;
	}
	if (step == 0)
	{
		printf("export: '%s': not a valid identifier\n", var);
		return (false);
	}
	if (*var == '=')
		if (*(var + 1))
			return (true);
	return (false);
}
