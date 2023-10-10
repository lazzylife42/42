/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:50:51 by sab               #+#    #+#             */
/*   Updated: 2023/10/10 13:57:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define TRUE  1
# define FALSE 0

typedef struct t_cell
{
	int				data;
	int				index;
	struct t_cell	*next;
	struct t_cell	*prev;
}t_stack;

/*	ERROR, INIT AND FREE	*/

void	stack_init(t_stack **a, char **argv);
void	free_stack(t_stack **node);

/*	LINKED LIST				*/

int		stack_sorted(t_stack *stack);
void	ft_lprint(t_stack *node);
int		ft_llen(t_stack *node);
int		ft_lpush(t_stack **head, int new_data);
int		ft_lpush_back(t_stack **head, int new_data);
int		ft_ldelete(t_stack **head, t_stack *del);

/*	INDEX SORT				*/

t_stack	*index_sort(t_stack *a);

/*	SMALL SORT				*/

void	tiny_sort(t_stack **a);
void	small_sort(t_stack **a, t_stack **b);
void	four_sort(t_stack **a, t_stack **b);
void	five_sort(t_stack **a, t_stack **b);

/*	RADIX SORT				*/

t_stack	*find_highest(t_stack *node);
t_stack	*find_lowest(t_stack *node);
void	radix(t_stack **a, t_stack **b);
void	update_index(t_stack *head);

/*	COMMANDS				*/

void	sa(t_stack **a);
void	sb(t_stack **b);
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