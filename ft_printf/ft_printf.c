/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sab <sab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:19:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/05/04 11:35:46 by sab              ###   ########.fr       */
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

int		ft_printf_conv(char format, va_list ap)
{
	if (format == '%')
		return (ft_printf_char('%'));
	else if (format == 'c')
		return (ft_printf_char(va_arg(ap, char)));
	else if (format == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printf(''))
	
}