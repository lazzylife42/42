/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:33:11 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/04 18:05:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char const **argv)
{
	pid_t father;

	(void)argc;
	(void)argv;
	father = fork();
	if (father > 0)
	{
		wait(0);
		ft_printf("Call Me PAPY\n");
	}
	else if (father == 0)
	{
		sleep(5);
		char *const args[] = {"/bin/ls", NULL};
		execve("/bin/ls", args, NULL);
	}
	return 0;
}

