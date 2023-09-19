/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:06:48 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/03 00:00:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// gcc split.c test_split.c push_swap.h -g

int main(int argc, char **argv)
{
	char	*str;
	char 	**array;
	int		i, j, id, count;

	i = 0;
	j = 0;
	id = 1;
	count = 0;

	printf("argc : %i\n", argc);

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
	while (array[i])
	{
		printf("id[%i] : %s\n",i, array[i]);
		i++;
		j++;
	}
	return 0;
}
