/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:01:31 by lmedrano          #+#    #+#             */
/*   Updated: 2024/03/12 14:02:17 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
