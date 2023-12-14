/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:14 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/14 19:25:56 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc *.c *.h -lft -L../libft

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
	char			*cmd;
	char			*arg;
	t_pipe			*pipe;
}					t_sep;

typedef struct s_exec
{
	t_sep			*separator;
	struct s_exec	*next;
}					t_exec;

/*		FUNC			*/

int					is_separator(char *token);
int					is_agrument(char *token);
int					count_separators(char **tokens);
t_exec				*parse(t_exec *to_run, char **tokens, char **env);

/*		UTILS			*/

t_sep				*create_sep_node(char *cmd, char *arg, char *token, char *file);
t_exec				*add_to_exec_list(t_exec *head, t_sep *new_node);
void				print_to_run(t_exec *to_run);

#endif