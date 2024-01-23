/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:17:48 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/23 15:05:20 by smonte-e         ###   ########.fr       */
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

void	exec_heredoc(char **input)
{
	char	*heredoc_txt;

	heredoc_txt = heredoc(input[1]);
	if (!heredoc_txt)
		return ;
	ft_putstr_fd(heredoc_txt, 1);
	free(heredoc_txt);
}

void	handle_heredoc(t_exec **to_run)
{
	char	*heredoc_txt;
	int		heredoc_fd;

	if (!(*to_run)->next || !(*to_run)->next->separator
		|| !(*to_run)->separator->arg[1])
	{
		perror(RED"Error: separator not properly initialized.\n"RST);
		return ;
	}
	if (!(*to_run)->next->separator->file_in)
		(*to_run)->next->separator->file_in = "heredoc.tmp";
	heredoc_txt = heredoc((*to_run)->separator->arg[1]);
	if (!heredoc_txt)
		return ;
	heredoc_fd = open((*to_run)->next->separator->file_in,
			O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (heredoc_fd == -1)
	{
		perror(RED"Open"RST);
		free(heredoc_txt);
		return ;
	}
	ft_putstr_fd(heredoc_txt, heredoc_fd);
	close(heredoc_fd);
	free(heredoc_txt);
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