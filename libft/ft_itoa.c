/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:57:24 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 17:40:02 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts the number of characters in a number
/// @param n integer number, treated as long int for simplicity
/// @return Number of characters in the number
static int	numstrlen(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++i;
	}
	while (n > 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

/// @brief Converts an integer number to a string
/// @param n Integer number to convert
/// @return String representation of the number
char	*ft_itoa(int n)
{
	long int	num;
	char		*res;
	int			i;

	num = n;
	i = numstrlen((long int) n);
	res = (char *) malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[i--] = '\0';
	if (num < 0)
	{
		*res = '-';
		num *= -1;
	}
	if (num == 0)
		*res = '0';
	while (num > 0)
	{
		res[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
