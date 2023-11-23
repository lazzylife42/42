/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:12:35 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/23 14:22:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int ac, char **av)
{
    (void)av;
    t_table     table;
    
    if (ac == 5 || ac == 6)
    {
        return 1;
    }
    else
    {
        error_exit("Bad input\n"G"Try \"./philo 5 800 200 200 [5]\""RST);
    }
    return (0);
}