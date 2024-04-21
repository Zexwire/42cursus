/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:07:40 by mcarnere          #+#    #+#             */
/*   Updated: 2024/04/21 13:08:46 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			++count;
		}
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
		while (*(s + i) == c)
			++i;
		j = 0;
		while (*(s + i + j) && *(s + i + j) != c)
			++j;
		if (j > 0)
		{
			res[k] = ft_substr(s, i, j);
			++k;
		}
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
