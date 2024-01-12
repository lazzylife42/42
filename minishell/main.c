/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:15:43 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/10 14:54:08 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// resetting signal
// redirection, normal and with pipes
// $?

///////////// for testing
void	display_double_str(char **str)
{
	int	i = 0;

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

char	**get_prompt(char* prompt)
/*Give the prompt to the user, will wait for it to write something, will
keep it in memory, will ft_split it and return it*/
{
	char	*line_read;
	char	**res;

	line_read = readline(prompt);
	if (line_read == NULL)
		exit(1);
	if (line_read && *line_read)
	{
		add_history(line_read);
		res = minishell_split(line_read);
		free(line_read);
		return (res); 
	}
	return (NULL);
}

struct termios	set_signal()
{
	struct termios old_termios;
	struct termios new_termios;

	tcgetattr(0,&old_termios);
	new_termios = old_termios;
  	new_termios.c_cc[VEOF] = -1; //default 4
	new_termios.c_cc[VQUIT] = 4; //default 28
  	tcsetattr(0,TCSANOW,&new_termios);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	return(old_termios);
}

int main(int argc, char **argv, char **envp)
{
	char	**env;
	char 	**input;
	char	*directory;
	t_exec	*to_run;
	struct termios termios;

	termios = set_signal();
	to_run = NULL;
	(void)argc;
	(void)argv;
	directory = malloc(256);
	if (!directory)
		exit(1);
	env = duplicate_env(envp);
	if (!env)
		exit(1);
	if (getcwd(directory, 256) == NULL)// magic number for now...
		 perror("getcwd() error");
	while (1)
	{
		input = get_prompt(M"minishell> "RST);
		if (input)
		{
			display_double_str(input);
			to_run = parse(to_run, input);
			print_to_run(to_run);
			execute_all(to_run, &directory, &env);
			free_exec_list(to_run);
			to_run = NULL;
		}
		free_double_str(input);
	}
	free_double_str(env);
	tcsetattr(0,TCSANOW,&termios);/////is never called, should always be called (and correct)
	exit(0);
}
