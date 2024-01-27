/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:17:48 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/27 10:17:50 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -g heredoc.c ../minishell.h -lft -L../libft -lreadline
#include "../minishell.h"

char	*heredoc(const char *delimiter)
{
	char	*line;
	char	*heredoc_txt;

	heredoc_txt = NULL;
	while (1)
	{
		line = readline(YL "heredoc> " RST);
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		heredoc_txt = ralloc_str(heredoc_txt, line, ft_strlen(line));
		if (!heredoc_txt)
			shell_exit(1, NULL);
		heredoc_txt = ralloc_str(heredoc_txt, "\n", 1);
		if (!heredoc_txt)
			shell_exit(1, NULL);
		add_history(line);
		free(line);
	}
	return (heredoc_txt);
}

void	exec_heredoc(char **input, char ***env)
{
	char	*heredoc_txt;

	heredoc_txt = heredoc(input[1]);
	if (!heredoc_txt)
		return ;
	ft_putstr_fd(heredoc_txt, 1);
	free(heredoc_txt);
	set_dollar(env, 0);
}

void	handle_heredoc(t_exec **to_run, char ***env)
{
	char	*heredoc_txt;
	int		heredoc_fd;

	if (!(*to_run)->next || !(*to_run)->next->separator
		|| !(*to_run)->separator->arg[1])
	{
		perror("Error: separator not properly initialized.\n");
		return (set_dollar(env, 1));
	}
	if (!(*to_run)->next->separator->file_in)
		(*to_run)->next->separator->file_in = "heredoc.tmp";
	heredoc_txt = heredoc((*to_run)->separator->arg[1]);
	if (!heredoc_txt)
		return (set_dollar(env, 1));
	heredoc_fd = open((*to_run)->next->separator->file_in,
			O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (heredoc_fd == -1)
	{
		perror("Open");
		return (free(heredoc_txt));
	}
	ft_putstr_fd(heredoc_txt, heredoc_fd);
	close(heredoc_fd);
	free(heredoc_txt);
}

int	find_heredoc_position(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strncmp(args[i], "<<", 2) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	arg_heredoc(t_sep **separator, char ***env)
{
	char	**args;
	char	*heredoc_txt;
	int		heredoc_pos;
	int		fd_heredoc;

	args = (*separator)->arg;
	heredoc_pos = find_heredoc_position(args);
	if (heredoc_pos == -1 || args[heredoc_pos + 1] == NULL)
		return ;
	heredoc_txt = heredoc(args[heredoc_pos + 1]);
	if (!heredoc_txt)
	{
		perror("Erreur lors de la récupération de l'heredoc");
		return (set_dollar(env, 1));
	}
	fd_heredoc = open("heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_heredoc == -1)
	{
		perror("Erreur lors de la création du fichier heredoc.tmp");
		free(heredoc_txt);
		return (set_dollar(env, 1));
	}
	write(fd_heredoc, heredoc_txt, ft_strlen(heredoc_txt));
	close(fd_heredoc);
	(*separator)->file_in = ft_strdup("heredoc.tmp");
	free(heredoc_txt);
	while (args[heredoc_pos])
	{
		args[heredoc_pos] = NULL;
		heredoc_pos++;
	}
}

// void	rm_heredoc(const char *file_in)
// {
// 	if (file_in == NULL || file_in[0] == '\0')
// 		return ;
// 	if (unlink(file_in) == -1)
// 	{
// 		perror("Unlink");
// 		shell_exit(1);
// 	}
// }

// int	main(void)
// {
// 	char *heredoc_txt = heredoc("EOF");
// 	printf("Heredoc Text:\n%s\n", heredoc_txt);
// 	free(heredoc_txt);
// 	return (0);
// }