/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:01:52 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:51:04 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Searches for the first occurrence of the substring needle 
/// in the string haystack, where not more than len characters are searched
/// @param haystack String to search in
/// @param needle String to search for
/// @param len Number of characters to search
/// @return Pointer to the found string, NULL if not found
char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (haystack == needle)
		return ((char *) haystack);
	if (len < 0)
		len = ft_strlen(haystack);
	while (haystack[i] != '\0' && i <= len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0')
			j++;
		if (needle[j] == '\0' && (i + j) <= len)
			return ((char *) haystack + i);
		i++;
		j = 0;
	}
	if (needle[j] == '\0')
		return ((char *) haystack);
	return (NULL);
}
