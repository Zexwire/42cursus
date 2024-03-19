/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:57:24 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 17:36:37 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numstrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		++i;
	}
	while (n / 10 > 9)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = numstrlen(n);
	res = malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	--i;
	while (i > 0)
	{
		res[i] = (n % 10);
		n /= 10;
		--i;
	}
	if (n < 0)
		*res = '-';
	else
		*res = (n % 10);
	return (res);
}
