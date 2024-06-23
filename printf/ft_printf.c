/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:04:04 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/23 19:12:00 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Auxiliar function to parse_format, treating the cases of 
/// %d, %i, %u, %x, %X and %p format specifiers
/// @param format String with the format specifier
/// @param argptr Pointer to the arguments list
/// @param count Pointer to the counter of printed characters
static void	parse_format2(char const *format, va_list argptr, int *count)
{
	unsigned long long	addr;

	if (*format == 'd' || *format == 'i')
		ft_printnbr(va_arg(argptr, int), count);
	else if (*format == 'u')
		ft_printuns(va_arg(argptr, unsigned int), count);
	else if (*format == 'x')
		ft_printhexa((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789abcdef", count);
	else if (*format == 'X')
		ft_printhexa((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789ABCDEF", count);
	else if (*format == 'p')
	{
		addr = (unsigned long long) va_arg(argptr, void *);
		if (addr == 0)
		{
			write(1, "(nil)", 5);
			*count += 5;
			return ;
		}
		write(1, "0x", 2);
		*count += 2;
		ft_printhexa(addr, "0123456789abcdef", count);
	}
}

/// @brief Function to parse the format specifier and 
/// call the corresponding function to print the argument
/// it treats the cases of %%, %c and %s format specifiers
/// @param format String with the format specifier
/// @param argptr Pointer to the arguments list
/// @param count Pointer to the counter of printed characters
static void	parse_format(char const *format, va_list argptr, int *count)
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
