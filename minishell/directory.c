/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:33:16 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/11 12:41:25 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_new_directory(char **directory, char *str)
{
	if (chdir(str) != 0)
	{
		perror("chdir() error()");
		return ;
	}
	if (getcwd(*directory, 256) == NULL) // magic number for now...
		perror("getcwd() error");
}