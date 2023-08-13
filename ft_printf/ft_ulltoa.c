/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:56:33 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/13 18:18:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ullen_base(unsigned long long number, char *base)
{
	int	len;
	
	len = 0;
	if (len == 0)
		len++;
	while (number > 0)
	{
		number /= ft_strlen(base);
		len++;
	}
	return (len);
}

char *ft_ulltoa_base(unsigned long long number, char *base)
{
	int		i;
	char	*str;

	i = ft_ullen_base(number, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i--] = base[number % ft_strlen(base)];
		number /= ft_strlen(base);
	}
	return (str);
}