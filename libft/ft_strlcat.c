/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:56:34 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 19:45:11 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
