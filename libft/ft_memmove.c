/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:20:08 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:31:49 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies len bytes from string src to string dst
/// even if the strings overlap.
/// @param dst Destination memory area
/// @param src Source memory area
/// @param len Number of bytes to copy
/// @return Pointer to the destination memory area, NULL if wrong parameters
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;
	int			i;

	ptr_dst = (char *) dst;
	ptr_src = (char *) src;
	if (!dst && !src && len > 0)
		return (NULL);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			*(ptr_dst + i) = *(ptr_src + i);
			--i;
		}
	}
	return (dst);
}
