/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:44:39 by smonte-e          #+#    #+#             */
/*   Updated: 2023/02/22 13:51:27 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf_ui(unsigned int n);
int		ft_printf_conv(char format, va_list ap);
int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_strlen(const char *s);
int		ft_printf_n_base(long long num, char *base);
int		ft_printf_ptr(unsigned long ptr);
char	*ft_ulltoa_base(unsigned long long n, char *base);
int		ft_printf(const char *format, ...);

#endif