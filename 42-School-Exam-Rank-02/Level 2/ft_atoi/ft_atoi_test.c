/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:15:58 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *str)
{
    int result;
    int signe;
    int i;

    i = 0;
    result = 0;
    signe = 1;
    if (str[i] == '-')
    {    
        signe = signe * -1;
        i++;
    }   
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
    return (result * signe);
}


#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d", ft_atoi(argv[1]));
}