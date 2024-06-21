/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:04:04 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/21 18:47:12 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	ft_putnbr_uns(unsigned long long nbr, char *base, int *count)
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

void	parse_format2(char const *format, va_list argptr, int *count)
{
	unsigned long long	addr;

	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(argptr, int), count);
	else if (*format == 'u')
		ft_putnbr_uns((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789", count);
	else if (*format == 'x')
		ft_putnbr_uns((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789abcdef", count);
	else if (*format == 'X')
		ft_putnbr_uns((unsigned long long)
			va_arg(argptr, unsigned int), "0123456789ABCDEF", count);
	else if (*format == 'p')
	{
		write(1, "0x", 2);
		addr = (unsigned long long) va_arg(argptr, void *);
		ft_putnbr_uns(addr, "0123456789abcdef", count);
	}
}

// FIXME: tengo que comprobar que lo que me pasan es efectivamente lo que quiero
// tanto numero de parametros como tipo de parametros
void	parse_format(char const *format, va_list argptr, int *count)
{
	char	*str;
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
	{
		str = va_arg(argptr, char *);
		aux = ft_strlen(str);
		*count += aux;
		write(1, str, aux * sizeof(char));
	}
	else
		parse_format2(format, argptr, count);
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
	va_end(argptr);
	return (count);
}

#include <stdio.h>

int	main()
{
// NORMAL TESTS CASES

    // Test case 1: Printing a string
    ft_printf("Hello, world!\n");
	printf("Hello, world!\n");

    // Test case 2: Printing an integer
    int num = INT_MIN;
    ft_printf("The answer is %i\n", num);
	printf("The answer is %i\n", num);
	
    ft_printf("The answer is %d\n", num);
	printf("The answer is %d\n", num);

    // Test case 3: Printing a character
    char ch = 'A';
    ft_printf("The character is %c\n", ch);
	printf("The character is %c\n", ch);

    // Test case 4: Printing a hexadecimal number
    unsigned int hex = 0xABCD;
    ft_printf("The hexadecimal number is %X\n", hex);
	printf("The hexadecimal number is %X\n", hex);

	// Test case 5: Printing a lowercase hexadecimal number
	unsigned int hexl = 0xABCD;
	ft_printf("The lowercase hexadecimal number is %x\n", hexl);
	printf("The lowercase hexadecimal number is %x\n", hexl);

    // Test case 6: Printing a pointer
    int *ptr = &num;
    ft_printf("The pointer is %p\n", ptr);
	printf("The pointer is %p\n", ptr);

	// Test case 7: Printing a string from a pointer
	char *str = "Hello, world!";
	ft_printf("The string is %s\n", str);
	printf("The string is %s\n", str);

	// Test case 8: Printing an unsigned integer
	unsigned int unum = UINT_MAX;
	ft_printf("The unsigned integer is %u\n", unum);
	printf("The unsigned integer is %u\n", unum);

	// Test case 9: Printing a percentage sign
	ft_printf("The percentage sign is %%\n");
	printf("The percentage sign is %%\n");

	// Test case 10: Printing everything together
	ft_printf("The answer is %%%i, the hexadecimal number is %X%%%x, the pointer is %p,the string is %s, the unsigned integer is %u, the character is %c\n", 
	num, hex, hex, ptr, str, unum, ch);
	printf("The answer is %%%i, the hexadecimal number is %X%%%x, the pointer is %p,the string is %s, the unsigned integer is %u, the character is %c\n",
	num, hex, hex, ptr, str, unum, ch);
	
// ERROR TEST CASES
	// Test case 11: Trying to print a string with a character specifier
	ft_printf("The string is %c\n", str);
	//printf("The string is %c\n", str);

	// Test case 12: Trying to print a character with a string specifier
	ft_printf("The character is %s\n", ch);
	printf("The character is %s\n", ch);

	// Test case 13: Trying to print a string with an integer specifier
	ft_printf("The string is %i\n", str);
	//printf("The string is %i\n", str);

	// Test case 14: Trying to print an integer with a string specifier
	ft_printf("The integer is %s\n");
	printf("The integer is %s\n");

    return (0);
}
