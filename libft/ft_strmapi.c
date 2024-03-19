/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:31:13 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 17:45:47 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;

	res = ft_strdup(s);
	if (!res)
		return (NULL);
	ft_striteri(res, f);
	return (res);
}
