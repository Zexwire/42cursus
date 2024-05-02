/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:57:46 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:50:09 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares at most the first n bytes of two strings
/// @param s1 First string
/// @param s2 Second string
/// @param n Number of bytes to compare
/// @return Difference between the first different character, 
/// > 0 if s1 > s2, < 0 if s1 < s2, 0 if equal
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if ((str1[i] - str2[i]) != 0)
			return (str1[i] - str2[i]);
		++i;
	}
	return (0);
}
