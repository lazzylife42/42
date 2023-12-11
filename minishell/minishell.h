/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:23:21 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/11 14:32:42 by smonte-e         ###   ########.fr       */
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
# include <sys/wait.h>
# include <fcntl.h>

void	set_new_directory(char **directory, char *str);

int		double_str_len(char **str);
char	**duplicate_env(char **env);

void	free_double_str(char **str);

/*  execute     */

void	execute(char *argv, char **envp);
char	*find_path(char *argv, char **envp);

#endif