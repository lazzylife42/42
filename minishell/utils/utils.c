/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:05:14 by nreichel          #+#    #+#             */
/*   Updated: 2024/01/22 14:09:02 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_dollar(char ***env, int n)
{
	char	*str;
	char	*itoa;

	itoa = ft_itoa(n);
	if (!itoa)
		shell_exit(1);
	str = ft_strjoin("?=", itoa);
	free(itoa);
	export_one(env, str, true);
	free(str);
}
