/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:49:48 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 15:33:12 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Fills a block of memory with a particular value
/// @param s Pointer to the block of memory to fill
/// @param c Value to be set
/// @param len Number of bytes to be set to the value
/// @return Pointer to the memory area s
void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		++i;
	}
	return (s);
}
