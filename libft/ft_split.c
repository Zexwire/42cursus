/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:07:40 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/20 17:57:18 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			++count;
		++i;
	}
	return (count);
}

void	fill_split(const char *s, char c, char **res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			++i;
			continue ;
		}
		j = 0;
		while (*(s + i + j) && *(s + i + j) != c)
			++j;
		res[k] = ft_substr(s, i, j);
		++k;
		i += j;
	}
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**res;

	words = word_count(s, c);
	res = (char **) malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[words] = NULL;
	fill_split(s, c, res);
	return (res);
}
