/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:23:21 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/10 15:22:27 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h> 
# include <readline/readline.h>
# include <readline/history.h>

// Define ANSI escape sequences for text color

# define RST "\033[0m"
# define RED "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define YL "\033[1;33m"
# define B "\033[34m"
# define M "\033[1;35m"
# define C "\033[1;36m"
# define W "\033[37m"

/*		STRUCTURES		*/

typedef struct s_sep
{
	char			**arg;
	char			*rd_in;
	char			*rd_out;
	char			*file_in;
	char			*file_out;
	char			*pipe;
}					t_sep;

typedef struct s_exec
{
	t_sep			*separator;
	struct s_exec	*next;
}					t_exec;


/*  FUNCTIONS       */

void	echo(char **input, char ***inv);
void	export(char ***env, char **var);
void	unset(char ***env, char **var);
void	set_new_directory(char **directory, char *str, char ***env);
void	display_env(char **env);
char	*translate_quote(char *str, char **env);
char	**minishell_split(char *str);
int		double_str_len(char **str);
char	**duplicate_env(char **env);
void	free_double_str(char **str);
char	**ralloc(char **res);
char	*check_env(char **env, char *str, int len);
void	sighandler(int signum);
char	*alloc_first(char *str, int len);
char	*alloc_re(char *res, char *str, int len);
char	*ralloc_str(char *res, char *str, int len);
void	display_double_str(char **str);//test

///EXECUTE

void	execute_all(t_exec *to_run, char **directory, char ***env);
void	execute(char **input, char **directory, char ***env, t_sep *sep);
void	exec_redir_out(t_sep *sep, char *pathname, char **argv, char **env);
char	*heredoc(const char *delimiter);

/*		PARSER				*/

char				*get_file(char **tokens, int index);
char				*find_path(char *argv, char **env);
char				**parse_arg(char **tokens, char **env, int pos);
t_exec				*parse(t_exec *to_run, char **tokens, char **env);

/*		PARSER UTILS		*/

int					is_cmd(char *token, char **env);
int					is_separator(char *token);
int					is_redir(char *token);
int					count_cmd(char **tokens, char **env);
int					count_separators(char **tokens);

/*		LINKED LIST			*/

t_sep				*create_sep_node(char **arg, char **input, char *pipe, int pos);
t_exec				*add_to_exec_list(t_exec *head, t_sep *new_node);
void				free_exec_list(t_exec *head);
void				ft_free_split(char **arr);
void				print_to_run(t_exec *to_run);

#endif