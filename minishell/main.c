/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:15:43 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/11 14:31:15 by smonte-e         ###   ########.fr       */
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
		res = ft_split(line_read, ' ');
		// ft_split should also split at '|' (you don't need space when using pipes)
		free(line_read);
		printf(": %s", line_read);
		return (res); 
	}
	return (NULL);
}


void	echo(char **input)
{
	int	i;
	int	backslash;

	i = 0;
	backslash = true;
	if (ft_strncmp(input[i], "-n", 3) == 0)
	{
		backslash = false;
		i += 1;
	}
	
}

void	parse_input(char **input, char **directory, char ***env)
/*directory and env are modifiable*/
{
	env = NULL;
	int	i;
	int	len;

	i = 0;
	len = double_str_len(input);
	while (i < len)
	{
		if (ft_strncmp(input[i], "pwd", 4) == 0)
			printf("%s\n", *directory);
		else if (ft_strncmp(input[i], "echo", 5) == 0)
			echo(input + i + 1);
		else if (ft_strncmp(input[i], "cd", 3) == 0)
		{
			if (input[i + 1])
				set_new_directory(directory, input[i + 1]);
			else
				set_new_directory(directory, "/Users");// where to go if no value?
			i += 1;
		}
		i += 1;
	}
}

extern char **environ;

int main(void)
{
	char	**env;
	char 	**input;
	char	*directory;

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
		parse_input(input, &directory, &env);
		free_double_str(input);
	}
	free_double_str(env);
}