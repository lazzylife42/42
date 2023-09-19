/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:11 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/15 01:51:02 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include "push_swap/libft/libft.h"
# include "push_swap.h"
# include <libc.h>
# include <limits.h>
# include <unistd.h>

// typedef struct s_stack_node
// {
// 	int					value;
// 	int					current_position;
// //	int					push_price;
// //	int					above_median;/* BOOL */
// //	int					cheapest;/* BOOL */
// 	struct s_stack_node	*target_node;
// 	struct s_stack_node	*next;
// 	struct s_stack_node	*prev;
// }	List;

typedef	struct Cell_t
{
	int	data;
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

/* STACK creation */

/* LINKED LISTS utils */

List	*add_at(List *list, int data, int pos);
List	*free_at(List *list, int pos);
List	*array_to_llist(char **array, List *list, int argc);
void	print_list(List *list); // à effacer !
long	len_list(List *list);


/* ALGORITHME */

int		list_sorted(List *list);

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