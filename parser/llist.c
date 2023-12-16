/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:38:28 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/16 16:30:12 by smonte-e         ###   ########.fr       */
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

void	free_exec_list(t_exec *head)
{
	t_exec	*temp;
	int		i;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		if (temp->separator->pipe->symbol)
			free(temp->separator->pipe->symbol);
		if (temp->separator->pipe->file)
			free(temp->separator->pipe->file);
		if (temp->separator->pipe)
			free(temp->separator->pipe);
		i = 0;
		while (temp->separator->arg[i] != NULL)
		{
			free(temp->separator->arg[i]);
			i++;
		}
		if (temp->separator->arg)
			free(temp->separator->arg);
		// if (temp->separator->cmd)
		// 	free(temp->separator->cmd);
		// if (temp->separator)
		// 	free(temp->separator);
		free(temp);
	}
}

void	ft_free_split(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_to_run(t_exec *to_run)
{
	t_sep	*current_sep;
	int		i;
	char	**args;

	if (to_run == NULL)
	{
		printf("Nothing to execute...\n");
		return ;
	}
	while (to_run != NULL)
	{
		i = 0;
		current_sep = to_run->separator;
		if (current_sep != NULL)
		{
			if (current_sep->cmd != NULL)
				printf("Command :  [%s]\n", current_sep->cmd);
			else
				printf("Command is [null]\n");
			if (current_sep->arg != NULL)
			{
				args = current_sep->arg;
				while (args[i] != NULL)
				{
					printf("Argument:  [%s]\n", args[i]);
					i++;
				}
			}
			else
			{
				printf("Argument:  [null]\n");
			}
			if (current_sep->pipe != NULL && current_sep->pipe->symbol != NULL)
				printf("Operator:  [%s]\n", current_sep->pipe->symbol);
			else
				printf("Operator:  [null]\n");
			if (current_sep->pipe != NULL && current_sep->pipe->file != NULL)
				printf("File    :  [%s]\n", current_sep->pipe->file);
			else
				printf("File    :  [null]\n");
		}
		printf("---------\n");
		to_run = to_run->next;
	}
}
