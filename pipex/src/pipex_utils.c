/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:19:01 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/10 17:43:54 by smonte-e         ###   ########.fr       */
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
	free(cmd1);
	free(cmd2);
	return split;
}

void	execute(char **cmd, char **envp)
{
	char *tmp;
	tmp = find_path(cmd, envp);
	if(!tmp)
	{
		perror("<Cmd> not found\n");
		exit(EXIT_FAILURE);
	}
	execve(tmp, cmd, envp);
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

char	*find_path(char **cmd, char **envp)
{
	int i = 0;
	int v_access = 0;
	char **split;
	char *return_cmd;
	
	split = ft_split(envp[13], ':');
	split[0] = split[0] + 5;
	return_cmd = (char *)malloc(ft_strlen(envp[13]) + 1);
	while (split[i])
	{
		ft_strcat(return_cmd, split[i]);
		ft_strcat(return_cmd, "/");
		ft_strcat(return_cmd, cmd[0]);
		v_access = access(return_cmd, X_OK);
		if(v_access == 0)
			return (return_cmd);
		ft_memset(return_cmd, '\0',ft_strlen(return_cmd));
		i++;
	}
	free(split);
	free(return_cmd);
	return(NULL);
}