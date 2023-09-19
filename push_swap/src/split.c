/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:57:06 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/03 22:02:49 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_arr(char **tab)
{
	int	i;

	i = 0;
	while ((char *)tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (NULL);
}

int	count_words(char *str, char separator)
{
	char	last;
	int		i;
	int		w_count;

	last = separator;
	i = 0;
	w_count = 0;
	while (str[i] != '\0')
	{
		if (last == separator && str[i] != separator)
			w_count++;
		last = str[i];
		i++;
	}
	return (w_count);
}

static char	*word_dup(const char *str, size_t start, size_t end)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = (char)str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split(char *str, char separator)
{
	char	**split;
	size_t	i;
	size_t	j;
	int		w_start;

	split = (char **)malloc((count_words(str, separator) + 1) * sizeof(char *));
	if (!str || !split)
		return (NULL);
	i = -1;
	j = 0;
	w_start = -1;
	while (++i <= ft_strlen(str))
	{
		if (str[i] != separator && w_start < 0)
			w_start = i;
		else if ((str[i] == separator || i == ft_strlen(str)) && w_start >= 0)
		{
			split[j] = word_dup(str, w_start, i);
			if (!(split[j++]))
				return (free_arr(split));
			w_start = -1;
		}	
	}
	split[j] = NULL;
	return (split);
}
