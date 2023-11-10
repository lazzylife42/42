/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:33:43 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/10 14:40:34 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	error(void);
char	*find_path(char *cmd, char **envp);
char    ***parse_cmd(char **argv);
void    free_cmd(char ***cmd);
void	execute(char **cmd, char **envp);
void	child_process(char **argv, char **cmd, char **envp, int *fd);
void	parent_process(char **argv, char **cmd, char **envp, int *fd);

#endif