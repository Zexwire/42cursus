/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:40:46 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/22 13:03:54 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printuns(unsigned int nbr, int *count)
{
	char	number;

	if (nbr / 10 != 0)
		ft_printuns((nbr / 10), count);
	number = nbr % 10 + '0';
	++*count;
	write(1, &number, 1);
}

void	ft_printhexa(unsigned long long nbr, char *base, int *count)
{
	char	number;

	if (nbr / 16 != 0)
		ft_printhexa((nbr / 16), base, count);
	number = base[nbr % 16];
	++*count;
	write(1, &number, 1);
}

void	ft_printnbr(int n, int *count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			*count += 11;
			return ;
		}
		write(1, "-", 1);
		++*count;
		n *= -1;
	}
	ft_printuns(n, count);
}

void	ft_printstr(char *str, int *count)
{
	if (!str)
	{
		write(1, "(null)", 6 * sizeof(char));
		*count += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, sizeof(char));
		++*count;
		++str;
	}
}
