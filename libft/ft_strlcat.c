/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:56:34 by marvin            #+#    #+#             */
/*   Updated: 2024/03/16 10:56:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;

	i = 0;
	while (*(dest + i) && size > 0)
	{
		i++;
		size--;
	}
	j = 0;
	while (*(src + j) && size > 1)
	{
		*(dest + i) = *(src + j);
		j++;
		i++;
		size--;
	}
	if (size >= 1)
		*(dest + i) = '\0';
	while (*(src + j))
	{
		i++;
		j++;
	}
	return (i);
}
