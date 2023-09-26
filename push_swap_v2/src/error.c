/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:47:44 by sab               #+#    #+#             */
/*   Updated: 2023/09/26 18:17:34 by sab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int is_an_int(const char *str)
{
	int i;
	long long_val;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	long_val = ft_atol(str);
	if (long_val > INT_MAX || long_val < INT_MIN)
		return (-1);
	return (0);
}

static int has_duplicates(char **argv) 
{
    int i;
	int j;

	i = 1;
    while (argv[i] != NULL) 
	{
        j = i + 1;
        while (argv[j] != NULL) {
            if (ft_strcmp(argv[i], argv[j]) == 0) {
                return (-1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int error_check(char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_an_int(argv[i]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_FAILURE);
		}	
		i++;
	}
	if (has_duplicates(argv))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}