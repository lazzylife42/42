/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:17:48 by smonte-e          #+#    #+#             */
/*   Updated: 2024/01/18 17:58:00 by smonte-e         ###   ########.fr       */
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
		line = readline(YL"heredoc> "RST);
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		heredoc_txt = ralloc_str(heredoc_txt, line, ft_strlen(line));
		if (!heredoc_txt)
			exit (1);
		heredoc_txt = ralloc_str(heredoc_txt, "\n", 1);
		if (!heredoc_txt)
			exit (1);
		add_history(line);
		free(line);
	}
	return (heredoc_txt);
}
void	exec_heredoc(char **input, char ***env)
{
	char *heredoc_txt;

	heredoc_txt = heredoc(input[1]);
	free(input[1]);
	input = malloc(sizeof(heredoc_txt));
	ft_strlcpy(input[1], heredoc_txt, ft_strlen(heredoc_txt));
	free(heredoc_txt);
	echo(input + 1, env);
}


// int	main(void)
// {
// 	char *heredoc_txt = heredoc("EOF");
// 	printf("Heredoc Text:\n%s\n", heredoc_txt);
// 	free(heredoc_txt);
// 	return (0);
// }