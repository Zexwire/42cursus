/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:30:29 by mcarnere          #+#    #+#             */
/*   Updated: 2024/09/29 17:48:10 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Tweaked versión of strchr to only check for newline
/// @param s String to search in
/// @return Pointer to the found newline, NULL if not found
char	*ft_strchr_nwln(const char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return ((char *) s + i);
		++i;
	}
	return (NULL);
}

/// @brief Length of a string
/// @param s String to measure
/// @return Length of the string
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

// @brief Concatenates two strings in a new allocated string
/// @param s1 First string
/// @param s2 Second string
/// @return Pointer to the new string, NULL if the allocation fails
char	*ft_strjoin_tweaked(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(size * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		++j;
	}
	res[i + j] = '\0';
	return (res);
}

/// @brief Copies a string into allocated memory
/// @param s1 String to copy
/// @return Pointer to the new string, NULL if the allocation fails
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = ft_strlen(s1);
	res = (char *) malloc((i + 1) * sizeof (char));
	if (res == NULL)
		return (NULL);
	*(res + i) = '\0';
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		++i;
	}
	return (res);
}

/// @brief Allocates a substring from the string s with at most len characters
/// @param s String to extract from
/// @param start Index to start extracting from
/// @param len Number of characters to extract
/// @return Pointer to the new string, NULL if allocation fails
char	*ft_substr_tweaked(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	res = (char *) malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
