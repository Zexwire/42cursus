/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:35:12 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/20 19:07:26 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*str;
	unsigned char		ch;

	str = (unsigned char *) s;
	ch = (unsigned char *) c;
	while (str)
	{
		if (*str == c)
			return (str);
		++str;
	}
	if (!ch)
		return (str);
	return (NULL);
}
