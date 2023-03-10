/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:19:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/02/22 14:09:41 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list ap;
	int	len;
	int	i;
	
	va_start(ap, format);
	len = 0;
	i = 0;
	
	while (format[i])
	{
		if (format[i]  == '%')
		{
			i++;
			len += ft_printf_conv(format[i], ap);
		}
		else
			len += ft_printf_char(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}