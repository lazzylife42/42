/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:08:50 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/20 15:15:19 by nreichel         ###   ########.fr       */
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

void	unset(char ***env, char **var)
{
	int		i;
	int		len;
	char	*txt;
	int		step;

	i = 0;
	while (var[i])
	{
		txt = translate_quote(var[i], *env);
		step = 0;
		while ((*env)[step])
		{
			len = ft_strlen(txt);
			if (ft_strncmp((*env)[step], txt, len) == 0
					&& (*env)[step][len] == '=')
				env_ralloc_del(env, step);
			step += 1;
		}
		free(txt);
		i += 1;
	}
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

void	add_env(char *txt, char ***env)
{
	*env = ralloc(*env);
	if (!*env)
		exit (1);
	(*env)[double_str_len(*env)] = ft_strdup(txt);
	if (!(*env)[double_str_len(*env) - 1])
		exit(1);
}

void	export(char ***env, char **var)
{
	char	*check;
	int		len;
	int		i;
	char	*txt;

	i = 0;
	while (var[i])
	{
		len = 0;
		txt = translate_quote(var[i], *env);
		while (txt[len] && txt[len] != '=')
			len += 1;
		if (env_var_valid(txt))
		{
			check = check_env(*env, txt, len);
			if (check == NULL)
				add_env(txt, env);
			else
				update_env(env, txt, len);
		}
		free(txt);
		i += 1;
	}
}
