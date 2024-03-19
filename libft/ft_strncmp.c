/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:57:46 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 18:22:42 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char) s1;
	str2 = (unsigned char) s2;
	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if ((str1[i] - str2[i]) != 0)
			return (str1[i] - str2[i]);
		++i;
	}
	return (str1[i] - str2[i]);
}
