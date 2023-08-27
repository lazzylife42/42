/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:11 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/23 18:15:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap/libft/libft.h"
# include <libc.h>

# define TRUE = 1;
# define FALSE = 0;

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* INPUT of ./push_swap */

/* ERROR handler */

/* STACK creation */

/* LINKED LISTS utils */

/* ALGORITHME */

/* COMMANDS */
#endif