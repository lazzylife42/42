/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:44:39 by smonte-e          #+#    #+#             */
/*   Updated: 2023/02/24 20:46:34 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf_ui(unsigned int n);
int		ft_printf_conv(char format, va_list ap);
int		ft_printf_char(char c);//done
int		ft_printf_str(char *str);//done
int		ft_strlen(const char *s);//done
int		ft_printf_n_base(long long num, char *base);
int		ft_printf_ptr(unsigned long ptr);
char	*ft_ulltoa_base(unsigned long long n, char *base);
int		ft_printf(const char *format, ...);

#endif