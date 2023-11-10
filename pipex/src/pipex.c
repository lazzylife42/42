/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:57 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/10 18:04:29 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(char **argv, char **cmd, char **envp, int *fd)
{
	int		input_file;

	input_file = open(argv[1], O_RDONLY);
	if (input_file == -1)
	{
		perror("Can't open file\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(input_file, STDIN_FILENO);
	close(fd[0]);
	execute(cmd, envp);
}

void	parent_process(char **argv, char **cmd, char **envp, int *fd)
{
	int		output_file;

	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_file == -1)
	{
		perror("Can't open file\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(output_file, STDOUT_FILENO); 
	close(fd[1]);
	execute(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	char	***cmd;

	cmd = parse_cmd(argv);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, cmd[0], envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, cmd[1], envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Try: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	free_cmd(cmd);
	return (EXIT_SUCCESS);
}
