/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:23:21 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/14 15:20:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	char			*pipe;
	char			*file;
}					t_pipe;

typedef struct s_sep
{
	char			*cmd;
	char			*arg;
	t_pipe			*pipe;
}					t_sep;

typedef struct s_exec
{
	t_sep			*separators;
	struct t_exec	*next;
}					t_exec;

void				set_new_directory(char **directory, char *str);
char				**minishell_split(char *str);
int					double_str_len(char **str);
char				**duplicate_env(char **env);

void				free_double_str(char **str);

void	display_double_str(char **str); // test

/*  EXECUTE			*/

int					execute(char *argv, char **envp);
char				*find_path(char *argv, char **envp);

/*	EXEC OPERATORS	*/

int					execute_pipe(char *command1, char *command2, char **env);
int					execute_redir_out(char *command1, char *command2,
						char **env);
int					execute_redir_append(char *command1, char *command2,
						char **env);
int					execute_redir_in(char *command1, char *command2,
						char **env);

/*  PARSER     */

int					is_operator(char *token);
int					is_cmd(char *token, char **env);
int					is_arg(char *token);
int					count_sep(char **input);
t_exec				*parse_separators(char **input, char **env);
void				add_cmd(t_sep *operator, char ** token, int pos);
t_exec				*add_operator(t_exec *separator, char **token, int pos);
t_exec				*add_operator_to_exec(t_exec *separators, char **token,
						int pos);
void				print_separator(t_exec *separators);

#endif