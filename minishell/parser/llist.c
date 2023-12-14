/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:04:25 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/14 11:17:21 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sep	*create_cell(char *cmd_sep)
{
  t_sep	*cell;

  cell = malloc(sizeof(t_sep));
  if (!(cell))
  	return (NULL);
  cell->prev = NULL;
  cell->next = NULL;
  cell->pipcell = NULL;
  cell->cmd_sep = cmd_sep;
  return (cell);
}

t_sep	*add_cell(t_sep *list, char *cmd_sep, int pos)
{
  t_sep	*prec;
  t_sep	*cur;
  t_sep	*cell;
  int		i;

  cur = list;
  i = 0;
  cell = create_cell(cmd_sep);
  if (list == NULL)
  	return (cell);
  while (i < pos)
  {
  	i++;
  	prec = cur;
  	cur = cur->next;
  }
  prec->next = cell;
  cell->next = cur;
  return (list);
}
