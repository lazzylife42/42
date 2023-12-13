/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:33:16 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/13 14:04:43 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_new_directory(char **directory, char *str, char ***env)
{
	if (str)
	{
		str = translate_quote(str, env);
		if (chdir(str) != 0)
		{
			perror("chdir() error()");
			free(str);
			return ;
		}
		if (getcwd(*directory, 256) == NULL) // magic number for now...
			perror("getcwd() error");
		free(str);
	}
}