/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:29 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/14 15:28:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_cmd(char *token, char **env)
{
	if (find_path(token, env))
		return (1);
	return (0);
}

int	is_arg(char *token)
{
	if (ft_strncmp(token, "-", 1) == 0)
		return (1);
	return (0);
}

t_sep	*AnalyserTokens(char **tokens, int nb_tokens, char **env)
{
	t_sep	*cmd;
	int		i;
	int		cur_cmd;

	cmd = (t_sep *)malloc(sizeof(t_sep) * nb_tokens);
	i = 0;
	cur_cmd = 0;
	while (tokens[i])
	{
		if (cur_cmd >= nb_tokens)
			break ;
		if (is_operator(tokens[i]))
			add_op(cmd, tokens[i], &cur_cmd);
		else if (is_cmd(tokens[i], env))
			add_cmd(cmd, tokens[i], &cur_cmd);
		else if (is_arg(tokens[i]))
			add_arg(cmd, tokens[i], &cur_cmd);
		i++;
	}
	return (cmd);
}
