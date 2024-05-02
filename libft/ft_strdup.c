/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:19 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:39:01 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies a string into allocated memory
/// @param s1 String to copy
/// @return Pointer to the new string, NULL if the allocation fails
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
