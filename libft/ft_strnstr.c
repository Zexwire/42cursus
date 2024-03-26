/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:01:52 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:51:59 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
