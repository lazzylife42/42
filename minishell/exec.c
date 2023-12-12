/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:29 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/12 17:32:40 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TANT QUE l'utilisateur ne quitte pas le shell
//     1. Lire l'entrée utilisateur et la diviser en tokens
//     2. Analyser les tokens pour identifier les commandes, arguments,
//	redirections, etc.
//
//     POUR CHAQUE commande identifiée
//         1. Identifier le chemin absolu de la commande (vérifier les alias,
//	les fonctions, le PATH, etc.)
//         2. Séparer les arguments et les options de la commande
//
//         SI commande interne (ex: cd, echo, etc.)
//             Exécuter la commande interne avec les arguments appropriés
//         SINON
//             Créer un nouveau processus
//             SI le processus est le processus enfant
//                 Rediriger les flux d'entrée/sortie selon les spécifications (si nécessaire)
//                 Exécuter la commande avec les arguments donnés
//                 SI erreur lors de l'exécution
//                     Afficher un message d'erreur
//                     Sortir avec un code d'erreur approprié
//                 SINON
//                     Terminer le processus enfant avec un code de succès
//             SINON (processus parent)
//                 Attendre la fin du processus enfant
//                 Récupérer le statut de sortie
//                 Afficher les résultats ou les messages d'erreur appropriés
//     FIN POUR
// FIN TANT QUE
// Structure pour représenter une commande avec ses arguments

static int	is_operator(char *token)
{
	return (token[0] == '|' || token[0] == '>' || token[0] == '<');
}

static int	is_cmd(char *token, char **env)
{
	if (find_path(token, env))
		return (1);
	return (0);
}

static int	is_arg(char *token)
{
	if (ft_strncmp(token, "-", 1) == 0)
		return (1);
	return (0);
}

void	add_op(t_cmd *cmds, char *token, int *cur_cmd)
{
	cmds[*cur_cmd].redir_type = token;
	cmds[*cur_cmd].redir_file = NULL;
	(*cur_cmd)++;
}

void	add_cmd(t_cmd *cmds, char *token, int *cur_cmd)
{
	cmds[*cur_cmd].cmds = token;
	cmds[*cur_cmd].nb_arg = 0;
	(*cur_cmd)++;
}

void	add_arg(t_cmd *cmds, char *token, int cur_cmd)
{
	if (cmds[cur_cmd].nb_arg < MAX_ARG)
	{
		cmds[cur_cmd].arguments[cmds[cur_cmd].nb_arg] = token;
		cmds[cur_cmd].nb_arg++;
	}
	else
	{
		;
	}
}

t_cmd	*AnalyserTokens(char **tokens, int nb_tokens, char **env)
{
	t_cmd	*cmds;
	int		i;
	int		cur_cmd;

	cmds = (t_cmd *)malloc(sizeof(t_cmd) * nb_tokens);
	i = 0;
	cur_cmd = 0;
	while (tokens[i])
	{
		if (cur_cmd >= nb_tokens)
			break ;
		if (is_operator(tokens[i]))
			add_op(cmds, tokens[i], &cur_cmd);
		else if (is_cmd(tokens[i], env))
			add_cmd(cmds, tokens[i], &cur_cmd);
		else if (is_arg(tokens[i]))
			add_arg(cmds, tokens[i], cur_cmd);
		i++;
	}
	return (cmds);
}

void print_cmds(t_cmd *cmds, int nb_cmds)
{
    for (int i = 0; i < nb_cmds; i++)
    {
        printf("Commande %d : %s\n", i + 1, cmds[i].cmds);

        printf("Arguments : ");
        for (int j = 0; j < cmds[i].nb_arg; j++)
        {
            printf("%s ", cmds[i].arguments[j]);
        }
        printf("\n");

        printf("Redirection : %s\n\n", cmds[i].redir_type);
    }
}
