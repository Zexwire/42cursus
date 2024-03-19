/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:00:33 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:53:05 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	mod;

	res = 0;
	mod = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			mod *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += (*str - '0');
		str++;
	}
	return (res * mod);
}
