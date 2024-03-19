/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:19 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:45:13 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*aux;
	char	*res;

	i = 0;
	while (s1[i] != '\0')
		i++;
	aux = (char *) malloc((i + 1) * sizeof (char));
	if (aux == 0)
		return (0);
	res = aux;
	while (*s1)
	{
		*aux = *s1;
		aux++;
		s1++;
	}
	*aux = '\0';
	return (res);
}
