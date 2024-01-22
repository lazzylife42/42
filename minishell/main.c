/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:15:43 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/22 10:46:35 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// redirection without pipe
// heredoc
// $? should be good, maybe i missed some special cases
// execve exit status good?

///////////// for testing
void	display_double_str(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		printf("INPUT: \n");
		while (str[i])
		{
			printf("- %s\n", str[i]);
			i += 1;
		}
		printf("------------------ \n");
	}
}

char	**get_prompt(char *prompt)
/*Give the prompt to the user, will wait for it to write something, will
keep it in memory, will ft_split it and return it*/
{
	char	*line_read;
	char	**res;

	line_read = readline(prompt);
	if (line_read && *line_read)
	{
		add_history(line_read);
		res = minishell_split(line_read);
		free(line_read);
		return (res);
	}
	return (NULL);
}

void	minishell(char ***env, char **directory)
{
	char	**input;
	t_exec	*to_run;

	to_run = NULL;
	input = get_prompt(M"minishell> "RST);
	update_lastsig(env);
	if (input)
	{
		//display_double_str(input);
		set_env_us(env, input[double_str_len(input) - 1]);
		to_run = parse(to_run, input);
		print_to_run(to_run);
		execute_all(to_run, directory, env);
		free_exec_list(to_run);
		to_run = NULL;
	}
	free_double_str(input);
}

int	main(int argc, char **argv, char **envp)
{
	char	**env;
	char	*directory;

	set_signal();
	(void)argc;
	(void)argv;
	directory = malloc(256);
	if (!directory)
		shell_exit(1);
	env = duplicate_env(envp);
	if (!env)
		shell_exit(1);
	if (getcwd(directory, 256) == NULL) // magic number for now...
		perror("getcwd() error");
	while (1)
		minishell(&env, &directory);
	free_double_str(env);
	shell_exit(0);
}
