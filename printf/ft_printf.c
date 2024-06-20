/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:04:04 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/20 21:53:38 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n, int *count)
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
		ft_putnbr(n / 10, count);
	nbr = '0' + (n % 10);
	++*count;
	write(1, &nbr, 1);
}

void	ft_putnbr_uns(unsigned int nbr, char *base, int *count)
{
	char	number;
	int		len;

	len = ft_strlen(base);
	if (nbr / len != 0)
		ft_putnbr_uns((nbr / len), base, count);
	number = base[nbr % len];
	++*count;
	write(1, &number, 1);
}

// FIXME: tengo que comprobar que lo que me pasan es efectivamente lo que quiero
void	parse_format(char const *format, va_list argptr, int *count)
{
	char	*str;
	int		len;

	if (*format == '%')
	{
		*str = '%';
		write(1, str, 1);
		*count++;
	}
	else if (*format == 'c')
	{
		write(1, va_arg(argptr, char), 1);
		*count++;
	}
	else if (*format == 's')
	{
		str = va_arg(argptr, char *);
		len = ft_strlen(str);
		*count += len;
		write(1, str, len * sizeof(char));
	}
	else
		parse_format2(format, argptr, count);
}

void	parse_format2(char const *format, va_list argptr, int *count)
{
	unsigned long long	addr;

	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(argptr, int), count);
	else if (*format == 'u')
		ft_putnbr_uns(va_arg(argptr, unsigned int), "0123456789", count);
	else if (*format == 'x')
		ft_putnbr_uns(va_arg(argptr, unsigned int), "0123456789abcdef", count);
	else if (*format == 'X')
		ft_putnbr_uns(va_arg(argptr, unsigned int), "0123456789ABCDEF", count);
	else if (*format == 'p')
	{
		addr = va_arg(argptr, unsigned long long);

	}
}

// FIXME: tengo que traer libft ya que uso strlen
int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	argptr;

	count = 0;
	va_start(argptr, format);
	while (*format && count >= 0)
	{
		if (*format == '%')
		{
			++format;
			parse_format(format, argptr, &count);
		}
		else
		{
			write(1, format, 1);
			++count;
		}
		++format;
	}
	return (count);
}
