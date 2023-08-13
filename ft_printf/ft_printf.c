/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:19:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/13 18:17:20 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list variables;
	int	len;
	int	i;
	
	va_start(variables, format);
	len = 0;
	i = 0;
	
	while (format[i])
	{
		if (format[i]  == '%')
		{
			i++;
			len += ft_printf_conv(format[i], variables);
		}
		else
			len += ft_printf_char(format[i]);
		i++;
	}
	va_end(variables);
	return (len);
}

int		ft_printf_conv(char format, va_list variables)
{
	if (format == '%')
		return (ft_printf_char('%'));
	else if (format == 'c')
		return (ft_printf_char(va_arg(variables, int)));
	else if (format == 's')
		return (ft_printf_str(va_arg(variables, char *)));
	else if (format == 'p')
		return (ft_printf_str(va_arg(variables, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printf_n_base(va_arg(variables, int), "0123456789"));
	else if (format == 'u')
		return (ft_printf_ui(va_arg(variables, unsigned int)));
	else if (format == 'x')
		return (ft_printf_n_base(va_arg(variables, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_printf_n_base(va_arg(variables, unsigned int), "0123456789ABCDEF"));	
	else if (format == 'p')
		return (ft_printf_ptr((unsigned long)va_arg(variables, void *)));
	return (0);
}