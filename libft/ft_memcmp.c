/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:37:59 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:27:42 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares two memory blocks
/// @param s1 First memory block
/// @param s2 Second memory block
/// @param n Number of bytes to compare
/// @return Difference between the first different byte, 
/// > 0 if s1 > s2, < 0 if s1 < s2, 0 if equal
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if ((str1[i] - str2[i]) != 0)
			return (str1[i] - str2[i]);
		++i;
	}
	return (0);
}
