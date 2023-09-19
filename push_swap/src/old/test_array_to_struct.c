/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_to_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:31:31 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/13 00:17:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*str;
	char 	**array;
	int		i, id;
	List	*list;

	i = 0;
	id = 1;

	if (argc == 2)
		str = argv[1];
	else if (argc > 2)
	{
		str = (char *)malloc(sizeof(char *) * (argc));
		while (id < argc)
		{
			str = ft_strcat(str, argv[id]);
			id++;
			if (id < argc)
				str[ft_strlen(str)] = ' ';
		}
	}
	else
		return (0);
	array = ft_split(str, ' ');
	array_to_llist(array, list);
	
	return (0);
}