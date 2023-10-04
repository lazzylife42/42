/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:50:51 by sab               #+#    #+#             */
/*   Updated: 2023/10/04 14:57:27 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define TRUE 	1
#define FALSE	0

typedef struct t_cell
{
	int		data;
	int		pivot;
	int		p_first;
	int		p_last;
	int		price;
	int		next_to_move;
	struct t_cell *next;
	struct t_cell *prev;
}t_stack;

/*	ERROR, INIT AND FREE	*/

void	stack_init(t_stack **a, char **argv);
void 	free_stack(t_stack **node);

/*	LINKED LIST				*/

void	ft_lprint(t_stack *node);
void 	pll(t_stack *a, t_stack *b);
int		ft_llen(t_stack* node);
int		ft_lpush(t_stack** head, int new_data);
int		ft_lpush_back(t_stack** head, int new_data);
int		ft_ldelete(t_stack** head, t_stack* del);

void	set_data_at(t_stack* node, int data, int pos);
void	set_pivot_at(t_stack* node, int pos);
void	set_p_first(t_stack* node, int pos);
void	set_p_last(t_stack* node, int pos);

/*	ALGORYTHME				*/

t_stack	*find_highest(t_stack *node);
t_stack *find_lowest(t_stack *node) ;
void	tiny_sort(t_stack **a);
void	dollar_sort(t_stack *a, t_stack *b);
void 	push_or_rotate(t_stack **a, t_stack **b, int pivot);

/*	QUICK SORT				*/

void 	quick_sort(t_stack **a, t_stack **b);

/*	PRICE CALCULATOR		*/

int		stack_sorted(t_stack *stack);
int		stack_reverse_sorted(t_stack *stack);
void	refresh_price(t_stack *stack);
void	refresh_next(t_stack *stack);

/*	FIND NEXT MOVE			*/

/*	COMMANDS				*/

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