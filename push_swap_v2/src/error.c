/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:47:44 by sab               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/28 22:50:16 by smonte-e         ###   ########.fr       */
=======
/*   Updated: 2023/09/28 22:19:34 by smonte-e         ###   ########.fr       */
>>>>>>> 430902aa5c07740e74fae2eb8978a230e8102f3f
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static	int error_check(char **argv)
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

<<<<<<< HEAD
void	stack_init(t_stack *a, char **argv)
=======
void	stack_init(t_stack *a, t_stack *b, char **argv)
{
	int i;
	
	error_check(argv);
	i = 1;
	while (argv[i])
	{
		ft_lpush_back(&a, ft_atoi(argv[i]));
		i++;
	}
	pb(&a, &b);
	pb(&a, &b);
	if (b->data < b->next->data)
		rb(&b);
	refresh_price(a);
	refresh_next(a);
	ft_lprint(a);
	ft_lprint(b);
}

t_stack	*free_all(t_stack *node)
>>>>>>> 430902aa5c07740e74fae2eb8978a230e8102f3f
{
	int i;
	
	error_check(argv);
	i = 1;
	while (argv[i])
	{
		ft_lpush_back(&a, ft_atoi(argv[i]));
		i++;
	}
}

void free_stack(t_stack **node)
{
    t_stack *current = *node;
    t_stack *tmp;

	current = *node;
    while (current) 
	{
        tmp = current->next;
        free(current);
        current = tmp;
    }

    *node = NULL;
}