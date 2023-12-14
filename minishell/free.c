/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:28:18 by nreichel          #+#    #+#             */
/*   Updated: 2023/12/11 11:31:44 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_double_str(char **str)
/* used to free double pointer string */
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i += 1;
	}
	free(str);
}