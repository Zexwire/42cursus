/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:20:08 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:49:47 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_dst;
	char	*str_src;
	size_t	i;

	str_dst = (char *) dst;
	str_src = (char *) src;
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			str_dst[i] = str_src[i];
			++i;
		}
	}
	if (src < dst)
	{
		i = len;
		while (i >= 0)
		{
			str_dst[i] = str_src[i];
			--i;
		}
	}
	return (dst);
}
