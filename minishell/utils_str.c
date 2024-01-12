/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:27:32 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/11 09:24:40 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	double_str_len(char **str)
{
	int	res;

	res = 0;
	while (str[res])
		res += 1;
	return (res);
}

void	set_shlvl(char **res, char **env)
{
	int		shlvl;
	char	*str;
	char	*new;
	int		i;

	i = 0;
	shlvl = ft_atoi(check_env(env, "SHLVL", 5)) + 1;
	str = ft_itoa(shlvl);
	if (!str)
		exit(1);
	new = ft_strjoin("SHLVL=", str);
	if (!new)
		exit(1);
	free(str);
	while (res[i] && ft_strncmp(res[i], "SHLVL=", 6) != 0)
		i += 1;
	free(res[i]);
	res[i] = new;
}

void	set_minimum(char ***res)
{
	char	*pwd;
	char	dir[256];

	pwd = ft_strjoin("PWD=", getcwd(dir, 256));
	if (!pwd)
		exit(1);
	export_one(res, pwd);
	free(pwd);
	export_one(res, "SHLVL=1");
	//path?
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
		if (!res)
			exit(1);
		i += 1;
	}
	res[i] = NULL;
	if (res[0] == NULL)
		set_minimum(&res);
	else
		set_shlvl(res, env);
	//export_one(&res, "---");
	//export_one(&res, "?=0");
	return (res);
}
