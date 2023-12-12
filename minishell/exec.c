/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:29 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/12 12:08:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_COMMANDS 100 // Nombre maximal de commandes

char	*executed_commands[MAX_COMMANDS] = {NULL};
		// Tableau pour stocker les commandes exécutées

void	add_executed_command(char *command)
{
	// Ajoutez la commande au tableau des commandes exécutées
	// ...
}

int	already_executed(char *command)
{
	// Vérifiez si la commande a déjà été exécutée
	// Renvoyez 1 si elle a été exécutée, 0 sinon
	// ...
}

void	free_executed_commands(void)
{
	// Libérez la mémoire allouée pour les commandes exécutées
	// ...
}

int	execute_command(char *command, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	path = find_path(cmd[0], envp);
	if (already_executed(command))
	{
		printf("La commande a déjà été exécutée.\n");
		return (0);
	}
	if (path == NULL)
	{
		perror("Command not found.\n");
		return (-1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("Can't execute the command.\n");
		return (-1);
	}
	add_executed_command(command);
	return (0);
}

void	execute_operations(char **input, char **env)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!is_operator(input[i]))
		{
			execute_command(input[i], env);
		}
		else
		{
			exec_op(input, env, &i);
		}
		i++;
	}
}
/*
// int main() {
//     char **envp; // Définissez votre environnement

//     // Initialisez votre environnement,
	récupérez les commandes de l'utilisateur, etc.

//     // Exécutez les commandes
//     execute_operations(input_commands, envp);

//     // Libérez la mémoire allouée pour les commandes exécutées
//     free_executed_commands();

//     return (0);
// }
*/