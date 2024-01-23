/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:50:04 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/23 15:08:40 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_lastsig = -1;

void	update_lastsig(char ***env)
{
	if (g_lastsig != -1)
	{
		set_dollar(env, g_lastsig);
		g_lastsig = -1;
	}
}

struct termios	mem_termios(int n)
{
	static struct termios	old_termios;

	if (n == 0)
		tcgetattr(0, &old_termios);
	return (old_termios);
}

//default 4, new -1
//default 28, new 4
void	set_signal(void)
{
	struct termios	old_termios;
	struct termios	new_termios;

	old_termios = mem_termios(0);
	new_termios = old_termios;
	new_termios.c_cc[VEOF] = -1;
	new_termios.c_cc[VQUIT] = 4;
	tcsetattr(0, TCSANOW, &new_termios);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
}

// 0 = normal
// 1 = desactivated
// 2 = heredoc
int	sigactive(int arg)
{
	static int	state = 0;

	if (arg == -1)
		return (state);
	else
		state = arg;
	return (state);
}

void	sighandler(int signum)
{
	if (sigactive(-1) == 0)
	{
		if (signum == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_lastsig = 130;
		}
		else if (signum == SIGQUIT)
		{
			printf("\n");
			shell_exit(0, NULL);
		}
	}
}
