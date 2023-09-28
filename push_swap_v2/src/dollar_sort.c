/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:36:03 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/28 23:02:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	dollar_sort(t_stack *a, t_stack *b)
{    
	pb(&a, &b);
	pb(&a, &b);
	if ((b)->data < (b)->next->data)
		rb(&b);
	refresh_price(a);
	refresh_next(a);
	ft_lprint(a);
	ft_lprint(b);
}