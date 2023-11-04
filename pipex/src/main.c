/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:33:11 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/04 18:58:55 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char const **argv)
{
	pid_t	father;
	int		file0;
	int		file1;
	char	*cmd0;
	char 	*cmd1 = NULL;
	
	(void)argc;
	file0 = open(argv[1], O_RDWR);
	file1 = open(argv[4], O_RDWR);
	cmd0 = (char *)malloc((ft_strlen(argv[2]) + 6) * sizeof(char));
	cmd1 = (char *)malloc((ft_strlen(argv[3]) + 6) * sizeof(char));
	
	ft_strcat(cmd0, "/bin/");
	ft_strcat(cmd1, "/bin/");
	ft_strcat(cmd0, argv[2]);
	ft_strcat(cmd1, argv[3]);

	char *const c0[] = {cmd0, NULL};
	char *const c1[] = {cmd1, NULL};
	
	if (file0 == -1 || file1 == -1)
	{
		write(2, "Error\nCan't open file(s).\n", 27);
		exit(EXIT_FAILURE);
	}
	father = fork();
	if (father > 0)
	{
		wait(0);
		ft_printf("cmd 1 : '%s'\n", cmd1);
		execve(cmd1, c1, NULL);
	}
	else if (father == 0)
	{
		ft_printf("cmd 0 : '%s'\n", cmd0);
		execve(cmd0, c0, NULL);
	}
	free(cmd0);
	free(cmd1);
	return 0;
}

