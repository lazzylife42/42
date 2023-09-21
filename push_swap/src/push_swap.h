/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:11 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/21 21:19:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include "push_swap/libft/libft.h"
# include "push_swap.h"
# include <libc.h>
# include <limits.h>
# include <unistd.h>

enum naturel {SX, RX, RRX, SMALLEST, LARGEST, STACK_A, STACK_B};

typedef	struct Cell_t
{
	int	data;
	int price;
	struct Cell_t *next;
}List, Cell;

/* INPUT of ./push_swap */

char	**ft_split(char *str, char separator);
int		count_words(char *str, char separator);

/* ERROR handler */

void	free_matrix(char **arry);
void	free_stack(List **stack);
void	error_free(List **a, char **array);
int		error_repetition(List *a, int number);
int		error_syntax(char *str_number);

/* LINKED LISTS utils */

List	*add_at(List *list, int data, int pos);
List	*free_at(List *list, int pos);
List	*array_to_llist(char **array, List *list, int argc);
List	*free_list(List *list);
void	print_list(List *list); // à effacer !
long	len_list(List *list);

/* ALGORITHME */

int		list_sorted(List *list);
void	tiny_sort(List **a);
void    ghetto_sort(List **a, List **b);
void	play_maker(List *a);
void	b_boy(List *b);

/*	PRICE CALCULATOR */

List	*find_highest(List *list);
int		find_smallest(List *list);
int		find_largest(List *list);
int		n_val(List *list, int pos);
int		price_to_top(List *list, int pos);
int		find_pos_w_data(List *list, int data);
int		price_sx(int pos);
int 	price_rx(int pos);
int 	price_rrx(List *list, int pos);
int		move_sx_rx_rrx(List *list, int pos);
int		move_small_or_large(List *list, int smallest, int largest);

/* COMMANDS */

void	sa(List **a);
void 	sb(List **b);
void	ss(List **a, List **b);
void	ra(List **a);
void	rb(List **b);
void	rr(List **a, List **b);
void	rra(List **a);
void	rrb(List **b);
void	rrr(List **a, List **b);
void	pa(List **a, List **b);
void	pb(List **a, List **b);

/* UTILS */

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
long 	ft_atol(const char *str);

#endif