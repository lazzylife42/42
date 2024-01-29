/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:17:48 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/30 00:43:15 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_heredoc_position(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strncmp(args[i], "<<", 3) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	delete_heredoc(int heredoc_pos, t_sep **separator)
{
	while ((*separator)->arg[heredoc_pos])
	{
		(*separator)->arg[heredoc_pos] = NULL;
		heredoc_pos++;
	}
}

int	arg_heredoc(t_sep **separator, char ***env)
{
	char	**args;
	char	*heredoc_txt;
	int		heredoc_pos;
	int		fd_heredoc;

	args = (*separator)->arg;
	heredoc_pos = find_heredoc_position(args);
	if (heredoc_pos == -1 || args[heredoc_pos + 1] == NULL)
		return (0);
	heredoc_txt = heredoc(args[heredoc_pos + 1]);
	if (!heredoc_txt)
		return (set_dollar(env, 1), delete_heredoc(heredoc_pos, separator), 0);
	fd_heredoc = open("heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_heredoc == -1)
	{
		perror("Erreur lors de la création du fichier heredoc.tmp");
		free(heredoc_txt);
		return (set_dollar(env, 1), delete_heredoc(heredoc_pos, separator), 0);
	}
	write(fd_heredoc, heredoc_txt, ft_strlen(heredoc_txt));
	close(fd_heredoc);
	(*separator)->file_in = ft_strdup("heredoc.tmp");
	free(heredoc_txt);
	return (delete_heredoc(heredoc_pos, separator), 1);
}

void	process_heredocs(t_exec *to_run, char ***env)
{
	t_exec	*current;

	current = to_run;
	while (current != NULL)
	{
		if (current->separator != NULL)
		{
			arg_heredoc(&current->separator, env);
		}
		current = current->next;
	}
}