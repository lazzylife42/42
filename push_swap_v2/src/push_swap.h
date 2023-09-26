/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:50:51 by sab               #+#    #+#             */
/*   Updated: 2023/09/26 18:49:11 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct t_cell
{
	int index;
	int data;
	struct t_cell *next;
	struct t_cell *prev;
}t_stack;

/*	ERROR AND FREE	*/

int 	error_check(char **argv);
t_stack	*free_all(t_stack *node);

/*	LINKED LIST		*/

void	ft_lprint(t_stack *node);
int		ft_llen(t_stack* node);
int		ft_lpush(t_stack** head, int new_data);
int		ft_lpush_back(t_stack** head, int new_data);
int		ft_ldelete(t_stack** head, t_stack* del);

/*	ALGORYTHME		*/

/*	FIND NEXT MOVE	*/

/*	COMMANDS		*/

void	sa(t_stack **a);
void 	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

#endif