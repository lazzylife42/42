/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:17:48 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/20 18:41:45 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -g heredoc.c ../minishell.h -lft -L../libft -lreadline
#define MAX_LEN 10000

#include "../minishell.h"

char	*heredoc(const char *delimiter)
{
	char	*line;
	char	*heredoc_txt;

	heredoc_txt = (char *)malloc(sizeof(char) * MAX_LEN);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		ft_strcat(heredoc_txt, line);
		ft_strcat(heredoc_txt, "\n");
		add_history(line);
		free(line);
	}
	return (heredoc_txt);
}

// int	main(void)
// {
// 	char *heredoc_txt = heredoc("EOF");
// 	printf("Heredoc Text:\n%s\n", heredoc_txt);
// 	free(heredoc_txt);
// 	return (0);
// }