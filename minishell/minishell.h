/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:23:21 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/12 17:33:28 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>

#define MAX_ARG 42

typedef struct
{
	char	*cmds;
	char	*arguments[MAX_ARG];
	int		nb_arg;
	char	*redir_type;
	char	*redir_file;
}			t_cmd;

void	set_new_directory(char **directory, char *str);

char	**minishell_split(char *str);
int		double_str_len(char **str);
char	**duplicate_env(char **env);

void	free_double_str(char **str);


void	display_double_str(char **str);//test

/*  EXECUTE			*/

int		is_next_op(char **input, int pos);
int 	execute(char *argv, char **envp);
int 	exec_op(char **input, char **env, int *pos);
void    exec_cmd(char **input, char **env);
char	*find_path(char *argv, char **envp);

/*	EXEC OPERATORS	*/

int 	execute_pipe(char *command1, char *command2, char **env);
int 	execute_redir_out(char *command1, char *command2, char **env);
int 	execute_redir_append(char *command1, char *command2, char **env);
int 	execute_redir_in(char *command1, char *command2, char **env);

/*  EXEC PARSER     */

void    print_cmds(t_cmd *cmds, int nb_cmds);
void	add_op(t_cmd *cmds, char *token, int *cur_cmd);
void	add_cmd(t_cmd *cmds, char *token, int *cur_cmd);
void	add_arg(t_cmd *cmds, char *token, int cur_cmd);
t_cmd	*AnalyserTokens(char **tokens, int nb_tokens, char **env);

#endif