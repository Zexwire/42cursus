/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:35:12 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:10:06 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while (str != '\0')
	{
		if (*str == c)
			return (str);
		++str;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
