/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:29 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/20 17:56:18 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_contains(char c, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (set_contains(*(s1 + i), set))
		++i;
	j = ft_strlen(s1) - 1;
	while (set_contains(*(s1 + j), set))
		--j;
	if (i > j)
		return ("");
	res = ft_substr(s1, i, (j - i + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}
