/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:04:04 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/21 21:50:04 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format2(char const *format, va_list argptr, int *count)
{
	unsigned long long	addr;

	if (*format == 'd' || *format == 'i')
		ft_printnbr(va_arg(argptr, int), count);
	else if (*format == 'u')
		ft_printnbr_uns((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789", count);
	else if (*format == 'x')
		ft_printnbr_uns((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789abcdef", count);
	else if (*format == 'X')
		ft_printnbr_uns((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789ABCDEF", count);
	else if (*format == 'p')
	{
		write(1, "0x", 2);
		addr = (unsigned long long) va_arg(argptr, void *);
		ft_printnbr_uns(addr, "0123456789abcdef", count);
	}
}

void	ft_printstr(char *str, int *count)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6 * sizeof(char));
		*count += 6;
		return ;
	}
	len = ft_strlen(str);
	*count += len;
	write(1, str, len * sizeof(char));
}

void	parse_format(char const *format, va_list argptr, int *count)
{
	int		aux;

	if (*format == '%')
	{
		aux = '%';
		write(1, &aux, 1);
		++*count;
	}
	else if (*format == 'c')
	{
		aux = va_arg(argptr, int);
		write(1, &aux, 1);
		++*count;
	}
	else if (*format == 's')
		ft_printstr(va_arg(argptr, char *), count);
	else
		parse_format2(format, argptr, count);
}

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
	va_end(argptr);
	return (count);
}
