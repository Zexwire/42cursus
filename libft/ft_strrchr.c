/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:40:42 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/16 16:41:36 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*res;

	str = (char) s;
	res = NULL;
	while (str != '\0')
	{
		if (str == c)
			res = str;
		++str;
	}
	if (c == '\0')
		return (str);
	return (res);
}
