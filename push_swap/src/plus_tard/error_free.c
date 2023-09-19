/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 01:09:23 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/04 01:18:21 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **arry);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **a, char **array);
int		error_repetition(t_stack_node *a, int number);
int		error_syntax(char *str_number);