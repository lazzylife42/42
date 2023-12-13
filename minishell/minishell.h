/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:23:21 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/13 14:28:04 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h> 
# include <readline/readline.h>
# include <readline/history.h>

void	echo(char **input, char ***inv);
void	export(char *** env, char *var);
void	unset(char ***env, char *var);
void	set_new_directory(char **directory, char *str, char ***env);
void	display_env(char **env);

char	*translate_quote(char *str, char ***env);

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

#endif