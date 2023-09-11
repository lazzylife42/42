/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:53:56 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/12 01:27:08 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef	struct Cell_t
{
	int	data;
	struct Cell_t *next;
}List, Cell;

void	set_at(List *,int, int);
void	print_list(List *);
int		is_emplty_list(List *);
int		get_at(List *, int);
long	len_list(List *);
List	*empty_list(void);
List	*add_at(List *, int, int);
List	*free_at(List *, int);
List	*free_list(List *);

#endif
