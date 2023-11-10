/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:19:01 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/10 15:21:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

char ***parse_cmd(char **argv)
{
	char **cmd1;
	char **cmd2;
	char ***split;
	
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd1 || !cmd2)
	{
		ft_putstr_fd("Error: Memory allocation failure\n", 2);
		return (NULL);
	}
	split = (char ***)malloc(2 * sizeof(char **));
	split[0] = (char **)malloc(3 * sizeof(char *));
	split[1] =  (char **)malloc(3 * sizeof(char *));
	split[0][0] = cmd1[0];
	split[0][1] = cmd1[1];
	split[0][2] = NULL;
	split[1][0] = cmd2[0];
	split[1][1] = cmd2[1];
	split[1][2] = NULL;
	return split;
}

void	execute(char **cmd, char **envp)
{
	char *tmp;
	
//	if (cmd[1] != NULL)
//		ft_strcpy(cmd[1], cmd[1] + 1);
	tmp = (char *)malloc(ft_strlen("/bin/") + ft_strlen(cmd[0]) + 1);
	ft_strcpy(tmp, "/bin/");
	ft_strcat(tmp, cmd[0]);
	ft_strcpy(cmd[0], tmp);
	free(tmp);
	execve(cmd[0], cmd, envp);
}

void free_cmd(char ***cmd)
{
	free(cmd[0][0]);
	free(cmd[0][1]);
	free(cmd[0]);
	free(cmd[1][0]);
	free(cmd[1][1]);
	free(cmd[1]);
	free(cmd);
}
