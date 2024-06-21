/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:40:46 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/21 21:49:57 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_printnbr(int n, int *count)
{
	char	nbr;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		n *= -1;
	}
	if (n / 10 != 0)
		ft_printnbr(n / 10, count);
	nbr = '0' + (n % 10);
	++*count;
	write(1, &nbr, 1);
}

void	ft_printnbr_uns(unsigned long long nbr, char *base, int *count)
{
	char	number;
	int		len;

	len = ft_strlen(base);
	if (nbr / len != 0)
		ft_printnbr_uns((nbr / len), base, count);
	number = base[nbr % len];
	++*count;
	write(1, &number, 1);
}
