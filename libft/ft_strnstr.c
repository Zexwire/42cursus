/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:01:52 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/16 15:01:52 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && big[i + j] != '\0')
			j++;
		if (little[j] == '\0')
			return (big + i);
		i++;
		j = 0;
	}
	if (little[j] == '\0')
		return (big);
	return (0);
}