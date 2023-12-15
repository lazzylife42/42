/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:38:28 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/15 14:25:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_sep	*create_sep_node(char *cmd, char **arg, char *token, char *file)
{
	t_sep	*new_node;

	new_node = (t_sep *)malloc(sizeof(t_sep));
	if (new_node)
	{
		new_node->cmd = cmd;
		new_node->arg = arg;
		new_node->pipe = (t_pipe *)malloc(sizeof(t_pipe));
		if (new_node->pipe)
		{
			new_node->pipe->symbol = token;
			new_node->pipe->file = file;
		}
	}
	return (new_node);
}

t_exec	*add_to_exec_list(t_exec *head, t_sep *new_node)
{
	t_exec	*temp;
	t_exec	*current;

	temp = (t_exec *)malloc(sizeof(t_exec));
	if (temp)
	{
		temp->separator = new_node;
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			current = head;
			while (current->next != NULL)
				current = current->next;
			current->next = temp;
		}
	}
	return (head);
}
