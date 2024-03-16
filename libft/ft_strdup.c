/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:19 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/16 15:06:19 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*aux;
	char	*res;

	i = 0;
	while (src[i] != '\0')
		i++;
	aux = (char *) malloc((i + 1) * sizeof (char));
	if (aux == 0)
		return (0);
	res = aux;
	while (*src)
	{
		*aux = *src;
		aux++;
		src++;
	}
	*aux = '\0';
	return (res);
}