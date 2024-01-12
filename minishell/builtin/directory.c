/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:33:16 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/11 09:43:54 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_pwd_env(char *oldpwd, char ***env)
{
	char	*pwd;
	char	dir[256];

	pwd = ft_strjoin("PWD=", getcwd(dir, 256));
	if (!pwd)
		exit(1);
	export_one(env, pwd);
	export_one(env, oldpwd);
	free_two(pwd, oldpwd);
}

void	set_new_directory(char **directory, char *str, char ***env)
{
	char	*oldpwd;
	char	dir[256];

	if (!str)
		str = check_env(*env, "HOME", 4);
	if (str)
	{
		if (getcwd(dir, 256) != NULL)
		{
			oldpwd = ft_strjoin("OLDPWD=", dir);
			if (!oldpwd)
				exit(1);
		}
		str = translate_quote(str, *env);
		if (chdir(str) != 0)
		{
			perror("chdir() error");
			free_two(str, oldpwd);
			return ;
		}
		if (getcwd(*directory, 256) == NULL) // magic number for now...
			perror("getcwd() error");
		free(str);
		set_pwd_env(oldpwd, env);
	}
}
