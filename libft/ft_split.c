/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:07:40 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:31:37 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (s)
	{
		if (*s == c)
			++i;
	}
	return (i);
}

void	split_str(char **split, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (*str == c)
			i++;
		else
		{
			j = 0;
			while (*str != c)
				j++;
			split[word] = ft_substr(str, i, j);
			i += j;
			word++;
		}
	}
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		words;

	words = count_words(s, c);
	res = (char **) malloc(sizeof(char *) * (words + 1));
	res[words] = NULL;
	split_str(res, s, c);
	return (res);
}
