/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:12 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:25:47 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks for the first occurrence of the character c (an unsigned char)
/// in the first n bytes of the string pointed to by the argument s.
/// @param s Pointer to the memory area
/// @param c Character to check
/// @param n Number of bytes to check
/// @return Pointer to the matching byte or NULL if the character does not occur
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (str[i] == ch)
			return (str + i);
		++i;
	}
	return (NULL);
}
