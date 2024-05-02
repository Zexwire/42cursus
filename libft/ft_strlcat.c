/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:56:34 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 15:58:32 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Appends the NUL-terminated string src to the end of dst, 
/// at most dstsize - strlen(dst) - 1 characters will be copied
/// @param dst Destination string
/// @param src Source string
/// @param dstsize Size of the destination buffer
/// @return Length of the string that would have been created if enough space
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
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
