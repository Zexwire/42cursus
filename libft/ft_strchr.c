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
	char	*str;

	str = (char *) s;
	while (*str)
	{
		if (*str == (char) c)
			return (str);
		++str;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
