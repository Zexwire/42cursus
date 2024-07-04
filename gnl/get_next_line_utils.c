/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:42:54 by mcarnere          #+#    #+#             */
/*   Updated: 2024/07/04 22:20:50 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Appends the NUL-terminated string src to the end of dst, 
/// at most dstsize - strlen(dst) - 1 characters will be copied
/// @param dst Destination string
/// @param src Source string
/// @param dstsize Size of the destination buffer
/// @return Length of the string that would have been created if enough space
static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(dst + i) && dstsize > 0)
	{
		i++;
		dstsize--;
	}
	j = 0;
	while (*(src + j) && dstsize > 1)
	{
		*(dst + i) = *(src + j);
		j++;
		i++;
		dstsize--;
	}
	if (dstsize >= 1)
		*(dst + i) = '\0';
	while (*(src + j))
	{
		i++;
		j++;
	}
	return (i);
}

/// @brief Copy string src to dst, up to dstsize - 1 characters
/// @param dst Destination string
/// @param src Source string
/// @param dstsize Size of the destination buffer
/// @return Length of the string that would have been created 
/// if dst had enough space
static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0 || !src)
		return (ft_strlen(src));
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/// @brief Concatenates two strings in a new allocated string
/// @param s1 First string
/// @param s2 Second string
/// @return Pointer to the new string, NULL if the allocation fails
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(size * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, size);
	ft_strlcat(res, s2, size);
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;

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
	ft_strlcpy(res, (s + start), (len + 1));
	return (res);
}
