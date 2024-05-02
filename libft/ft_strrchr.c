/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:40:42 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:52:55 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks for the last occurrence of the character c in the string s
/// @param s String to search in
/// @param c Character to search for
/// @return Pointer to the found character, NULL if not found
char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char) c)
			res = (char *)(s + i);
		++i;
	}
	if ((char) c == '\0')
		return ((char *)(s + i));
	return (res);
}
