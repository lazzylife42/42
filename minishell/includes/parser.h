/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:07:06 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/08 15:16:44 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdlib.h>
#include <stdbool.h>
#include "../libft/libft.h"

typedef enum e_token_operator
{
	OR_COP = 10,          // ‘||’
	AND_COP,              // ‘&&’
	AMPERSAND_COP,        // ‘&’
	SEMICOLON_COP,        // ‘;’
	DOUBLE_SEMICOLON_COP, // ‘;;’
	SEMI_AND_COP,         // ‘;&’
	DOUBLE_SEMI_AND_COP,  // ‘;;&’
	PIPE_COP,             // ‘|’
	PIPE_AND_COP,         // ‘|&’
	COPEN_PAREN_COP,      // ‘(’
	CLOSE_PAREN_COP,      // ‘)’
	NEW_LINE_COP          // '\n'
}	t_token_operator;

typedef enum e_token_metacharacter
{
	SPACE_META = 100, // Space character
	TAB_META,         // Tab character
	NEWLINE_META,     // Newline character
	PIPE_META,        // ‘|’
	AMPERSAND_META,   // ‘&’
	SEMICOLON_META,   // ‘;’
	OPEN_PAREN_META,  // ‘(’
	CLOSE_PAREN_META, // ‘)’
	LESS_THAN_META,   // ‘<’
	GREATER_THAN_META // ‘>’
}	t_token_metachar;

char	**get_tokens(int argc, char **argv);

#endif