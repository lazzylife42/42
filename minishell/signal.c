/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:50:04 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/11 09:25:26 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	sigactive(int arg)
{
	static bool	active = true;

	if (arg == 1)
		active = true;
	else if (arg == -1)
		active = false;
	return (active);
}

void	sighandler(int signum)
{
	if (sigactive(0))
	{
		if (signum == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else if (signum == SIGQUIT)
			exit(1);
	}
}
