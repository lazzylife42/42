/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:08:50 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/13 14:13:44 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	unset(char ***env, char *var)
{
	int	i;
	int	len;

	var = translate_quote(var, env);
	i = 0;
	while ((*env)[i])
	{
		len = ft_strlen(var);
		if (ft_strncmp((*env)[i], var, len) == 0 && (*env)[i][len] == '=')
		{
			env_ralloc_del(env, i);
			free(var);
			return ;
		}
		i += 1;
	}
	free(var);
}

bool	env_var_valid(char *var)
{
	int	step;

	step = 0;
	while (*var && *var != '=')
	{
		if (!(ft_isalpha(*var) || *var == '_'))
			return (false);
		var += 1;
	}
	if (*var == '=')
		if (*(var + 1))
			return (true);
	return (false);
}

void	update_env(char ***env, char *var, int len)
{
	int	i;

	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], var, len) == 0 && (*env)[i][len] == '=')
		{
			free((*env)[i]);
			(*env)[i] = ft_strdup(var);
			if (!(*env)[i])
				exit(1);
			return ;
		}
		i += 1;
	}
}

void	export(char ***env, char *var)
{
	char	*check;
	int		len;

	len = 0;
	var = translate_quote(var, env);
	while (var[len] && var[len] != '=')
		len += 1;
	if (env_var_valid(var))
	{
		check = check_env(*env, var, len);
		if (check == NULL)
		{
			*env = ralloc(*env);
			if (!*env)
				return ;
			(*env)[double_str_len(*env)] = ft_strdup(var);
			if (!(*env)[double_str_len(*env) - 1])
				exit(1);
		}
		else
			update_env(env, var, len);
	}
	else
		printf("export: '%s': not a valid identifier\n", var);
	free(var);
}
