/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:20:08 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/16 16:33:36 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*str_dest;
	char	*str_src;
	int		i;

	str_dest = (char) dest;
	str_src = (char) src;
	if (src > dest)
	{
		i = 0;
		while (i < len)
		{
			str_dest[i] = str_src[i];
			++i;
		}
	}
	if (src < dest)
	{
		i = len;
		while (i >= 0)
		{
			str_dest[i] = str_src[i];
			--i;
		}
	}
	return (dest);
}
