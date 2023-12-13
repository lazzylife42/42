/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:29:55 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/13 14:14:54 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i += 1;
	}
}

void	echo(char **input, char ***env)
{
	int		i;
	int		backslash;
	char	*txt;

	i = 0;
	backslash = true;
	if (ft_strncmp(input[i], "-n", 3) == 0)
	{
		backslash = false;
		i += 1;
	}
	txt = translate_quote(input[i], env);
	if (!txt)
		return ;
	printf("%s", txt);
	free(txt);
	if (backslash)
		printf("\n");
}
