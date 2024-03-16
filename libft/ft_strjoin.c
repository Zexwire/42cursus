/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:11:06 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/16 17:56:23 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strcat_sep(int size, char **res, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		*res = ft_strcat(*res, *strs);
		*res = ft_strcat(*res, sep);
		strs++;
		++i;
	}
	*res = ft_strcat(*res, *strs);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*res;

	if (size == 0)
	{
		res = (char *) malloc(sizeof (char));
		*res = '\0';
		return (res);
	}
	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		++i;
	}
	len += (ft_strlen(sep) * (size - 1));
	res = (char *) malloc((len + 1) * sizeof (char));
	if (res == NULL)
		return (NULL);
	ft_strcat_sep(size, &res, strs, sep);
	res[len] = '\0';
	return (res);
}
