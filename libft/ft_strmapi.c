/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:31:13 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:45:09 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = ft_strlen(s);
	res = (char *) malloc((i + 1) * sizeof(char));
	res[i] = '\0';
	while (i > 0)
	{
		--i;
		res[i] = f(i, res[i]);
	}
	return (res);
}
