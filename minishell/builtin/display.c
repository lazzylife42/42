/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:29:55 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/08 15:47:16 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	while (input[i])
	{
		txt = translate_quote(input[i], *env);
		if (!txt)
			return ;
		if (ft_strncmp(txt, "-n", 3) == 0 && i == 0)
			backslash = false;
		else
		{
			if ((backslash && i >= 1) || (!backslash && i >= 2))
				printf(" ");
			printf("%s", txt);
		}
		i += 1;
		free(txt);
	}
	if (backslash)
		printf("\n");
}
