/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:24:49 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/20 19:12:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **input, char **directory, char ***env)
{
	char	*txt;

	txt = translate_quote(input[0], *env);
	if (ft_strncmp(txt, "echo", 5) == 0)
		echo(input + 1, env);
	else if (ft_strncmp(txt, "pwd", 4) == 0)
		printf("%s\n", *directory);
	else if (ft_strncmp(txt, "exit", 5) == 0)
		exit(1);
	else if (ft_strncmp(txt, "export", 7) == 0 || (ft_strncmp(txt, "setenv",
				7) == 0))
		export(env, input + 1);
	else if (ft_strncmp(txt, "unset", 6) == 0 || (ft_strncmp(txt, "unsetenv",
				9) == 0))
		unset(env, input + 1);
	else if (ft_strncmp(txt, "env", 4) == 0)
		display_env(*env);
	else if (ft_strncmp(txt, "cd", 3) == 0)
		set_new_directory(directory, input[1], env);
	else
		execve(find_path(txt, *env), input, *env);
	free(txt);
}

void	execute_all(t_exec *to_run, char **directory, char ***env)
{
	int	id;

	while (to_run)
	{
		if (pipe(to_run->separator->fd) == -1)
		{
			printf("An error occurred.");
			return ;
		}
		id = fork();
		if (id == 0)
		{
			execute(to_run->separator->arg, directory, env);
			exit(EXIT_SUCCESS);
		}
		else if (id > 0)
		{
			to_run = to_run->next;
			wait(NULL);
		}
		else
		{
			printf("Fork failed.\n");
			return ;
		}
	}
}
