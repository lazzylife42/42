/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:15:43 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/13 14:58:25 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_prompt(char* prompt)
/*Give the prompt to the user, will wait for it to write something, will
keep it in memory, will ft_split it and return it*/
{
	char *line_read;
	char **res;

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

void	parse_input(char **input, char **directory, char ***env)
/*directory and env are modifiable*/
{
	int	i;
	int	len;
	char	*txt;
	i = 0;
	len = double_str_len(input);
	while (i < len)
	{
		txt = translate_quote(input[i], env);
		if (ft_strncmp(txt, "pwd", 4) == 0)
			printf("%s\n", *directory);
		else if (ft_strncmp(txt, "echo", 5) == 0)
		{
			if (input[i + 1])
				echo(input + i + 1, env); // careful is -n
		}
		else if (ft_strncmp(input[i], "cd", 3) == 0)
		{
			if (input[i + 1])
				set_new_directory(directory, input[i + 1], env);
			else
				set_new_directory(directory, check_env(*env, "HOME", 4), env);
			i += 1;
		}
		else if (ft_strncmp(txt, "env", 4) == 0)
			display_env(*env);
		else if (ft_strncmp(txt, "unset", 6) == 0)
		{
			if (input[i + 1])
				unset(env, input[i + 1]);
		}
		else if (ft_strncmp(txt, "export", 7) == 0)
		{
			if (input[i + 1])
				export(env, input[i + 1]);
		}
		else if (ft_strncmp(txt, "exit", 5) == 0)
			exit(1);
		i += 1;
		free(txt);
	}
}
///////////// for testing
void	display_double_str(char **str)
{
	int	i = 0;

	while (str[i])
	{
		printf("- %s\n", str[i]);
		i += 1;
	}
}

extern char **environ;

int main(void)
{
	char	**env;
	char 	**input;
	char	*directory;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	directory = malloc(256);
	if (!directory)
		exit(1);
	env = duplicate_env(environ);
	if (!env)
		exit(1);
	if (getcwd(directory, 256) == NULL)// magic number for now...
		 perror("getcwd() error");
	while (1)
	{
		input = get_prompt("");
		if (input)
			parse_input(input, &directory, &env);
		free_double_str(input);
	}
	free_double_str(env);
}
