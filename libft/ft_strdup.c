/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:19 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 17:36:27 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies a string into allocated memory
/// @param s1 String to copy
/// @return Pointer to the new string, NULL if the allocation fails
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = ft_strlen(s1);
	res = (char *) malloc((i + 1) * sizeof (char));
	if (res == NULL)
		return (NULL);
	*(res + i) = '\0';
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		++i;
	}
	return (res);
}
