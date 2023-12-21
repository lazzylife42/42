/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:14 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/21 15:16:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -g *.c *.h -lft -L../libft

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

/*		STRUCTURES		*/

typedef struct s_pipe
{
	char			*symbol;
	char			*file;
}					t_pipe;

typedef struct s_sep
{
	int				fd[2];
	int				in_file;
	int				out_file;
	char			**arg;
	t_pipe			*pipe;
}					t_sep;

typedef struct s_exec
{
	t_sep			*separator;
	struct s_exec	*next;
}					t_exec;

/*		PARSER				*/

char				*get_file(char **tokens, int index);
char				*find_path(char *argv, char **env);
char				**parse_arg(char **tokens, char **env, int pos);
t_exec				*parse(t_exec *to_run, char **tokens, char **env);

/*		PARSER UTILS		*/

int					is_cmd(char *token, char **env);
int					is_separator(char *token);
int					count_cmd(char **tokens, char **env);
int					count_separators(char **tokens);

/*		LINKED LIST			*/

t_sep				*create_sep_node(char **arg, char *token, char *file);
t_exec				*add_to_exec_list(t_exec *head, t_sep *new_node);
void				free_exec_list(t_exec *head);
void				ft_free_split(char **arr);
void				print_to_run(t_exec *to_run);

#endif