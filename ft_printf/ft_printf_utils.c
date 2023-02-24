/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:12:38 by smonte-e          #+#    #+#             */
/*   Updated: 2023/02/24 20:27:11 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdarg.h>

int		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_printf_char(char c)
{
    return (write(1, &c, 1));
}

int	ft_printf_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			len += ft_printf_char(str[i]);
			i++;
		}
	}
	/*else
		len = ft_printf_str("(null)");*/
    return (len);
}