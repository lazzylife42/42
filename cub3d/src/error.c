/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:01:31 by lmedrano          #+#    #+#             */
/*   Updated: 2024/02/25 13:42:29 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_error_long(char *msg1, char *msg2)
{
	ft_putstr_fd(msg1, 2);
	ft_putstr_fd(msg2, 2);
	exit(EXIT_FAILURE);
}
