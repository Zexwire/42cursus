/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:07:40 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 17:29:35 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts the number of words in a string delimited by a character
/// @param s Original string
/// @param c Delimiter character
/// @return Number of words in the string
static int	word_count(const char *s, char c)
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

/// @brief Frees the memory allocated for the substrings
/// @param res Array of strings
/// @param k Number of strings in the array
static void	free_split(char **res, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(res[i]);
		i++;
	}
}

/*
Used an array to store the count of the characters in the string due to lines
 - Cont[0] is the usual i, the iteration in the string
 - Cont[1], being j, is the count of the characters in the next substring
 - Cont[2], being k is the index in res
*/
/// @brief Fills the array of strings with the substrings of the original string
/// @param s Original string
/// @param c Delimiter chaeacter
/// @param res Array of strings to store the substrings
/// @return 0 if successful, -1 if an error occurs
static int	fill_split(const char *s, char c, char **res)
{
	int	cont[3];

	cont[0] = 0;
	cont[2] = 0;
	while (*(s + cont[0]))
	{
		while (*(s + cont[0]) == c)
			++cont[0];
		cont[1] = 0;
		while (*(s + cont[0] + cont[1]) && *(s + cont[0] + cont[1]) != c)
			++cont[1];
		if (cont[1] > 0)
		{
			res[cont[2]] = ft_substr(s, cont[0], cont[1]);
			if (res[cont[2]] == NULL)
			{
				free_split(res, cont[2]);
				return (-1);
			}
			++cont[2];
		}
		cont[0] += cont[1];
	}
	return (0);
}

/// @brief Separates a string s into substrings delimited by a character c
/// @param s String to split
/// @param c Character to use as delimiter
/// @return Array of strings with the substrings. NULL terminated
char	**ft_split(const char *s, char c)
{
	int		words;
	char	**res;

	words = word_count(s, c);
	res = (char **) malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[words] = NULL;
	if (fill_split(s, c, res) == -1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
