/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:38:25 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/08 15:19:48 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// Créer une fonction pour parcourir les tokens et construire l'AST (parsing):
//   Pour chaque token dans argv:
//     Si c'est une nouvelle commande:
//       Créer un nouveau nœud de commande dans l'AST
//       Associer le token comme la nouvelle commande

//     Si c'est un argument:
//       Ajouter l'argument au nœud de commande actuel de l'AST

//     Si c'est une redirection ou un opérateur:
//       Gérer la redirection/opérateur en modifiant la structure de l'AST en conséquence

static bool	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

static char	*next_token(char *str)
{
	char	*start;
	char	quote;

	while (*str && *str == ' ')
		str++;
	if (!*str)
		return (NULL);
	start = str;
	if (is_quote(*str))
	{
		quote = *str;
		str++;
		while (*str && *str != quote)
			str++;
		if (*str == quote)
			str++;
	}
	else
	{
		while (*str && *str != ' ')
			str++;
	}
	if (*str == ' ')
	{
		*str = '\0';
		str++;
	}
	return (start);
}

char	**get_tokens(int argc, char **argv)
{
	int		i;
	int		index;
	int		token_count;
	char	**tokens;

	if (argc <= 1)
		return (NULL);
	else if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
	{
		token_count = 0;
		for (i = 1; i < argc; i++)
		{
			char *ptr = argv[i];
			while (next_token(ptr) != NULL)
			{
				token_count++;
				ptr = next_token(ptr);
			}
		}

		tokens = (char **)malloc(sizeof(char *) * (token_count + 1));
		if (!tokens)
			return (NULL);

		index = 0;
		for (i = 1; i < argc; i++)
		{
			char *ptr = argv[i];
			while ((tokens[index] = next_token(ptr)) != NULL)
			{
				index++;
				ptr = next_token(ptr);
			}
		}

		tokens[token_count] = NULL;
		return (tokens);
	}
}


int	main(int ac, char **av)
{
	int i = 0;
	char **tokens = get_tokens(ac, av);

	if (ac == 1)
		return (1);

	while (tokens[i])
	{
		ft_printf("token[%d]{%s}\n", i, tokens[i]);
		i++;
	}
	return (0);
}