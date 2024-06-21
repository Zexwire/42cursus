/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:30:00 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/21 21:47:05 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main()
{
	int num = INT_MIN;
    char ch = 'A';
    unsigned int hex = 0xABCD;
	unsigned int hexl = 0xABCD;
    int *ptr = &num;
	char *str = "Hello, world!";
	unsigned int unum = UINT_MAX;
// NORMAL TESTS CASES

    // Test case 1: Printing a string
    ft_printf("Hello, world!\n");
	printf("Hello, world!\n");

    // Test case 2: Printing an integer
    ft_printf("The answer is %i\n", num);
	printf("The answer is %i\n", num);
	
    ft_printf("The answer is %d\n", num);
	printf("The answer is %d\n", num);

    // Test case 3: Printing a character
    ft_printf("The character is %c\n", ch);
	printf("The character is %c\n", ch);

    // Test case 4: Printing a hexadecimal number
    ft_printf("The hexadecimal number is %X\n", hex);
	printf("The hexadecimal number is %X\n", hex);

	// Test case 5: Printing a lowercase hexadecimal number
	ft_printf("The lowercase hexadecimal number is %x\n", hexl);
	printf("The lowercase hexadecimal number is %x\n", hexl);

    // Test case 6: Printing a pointer
    ft_printf("The pointer is %p\n", ptr);
	printf("The pointer is %p\n", ptr);

	// Test case 7: Printing a string from a pointer
	ft_printf("The string is %s\n", str);
	printf("The string is %s\n", str);

	// Test case 8: Printing an unsigned integer
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
	// Test case 11: Trying to print a string with other specifiers
	ft_printf("The string is %s%c%X%x%d%u%p\n", str, str, str, str, str, str, str);

	// Test case 13: Trying to format nonexistent arguments
	ft_printf("They are %s%%%c%X%x%d%u%p\n");
	
	// Test case 11: Trying to print a something with %p
	ft_printf("The string is %p %p %p %p %p %p %p\n", num, hex, hex, ptr, str, unum, ch);

	// Test case 14: Trying to print something else with %s & %p
	ft_printf("The character is %s\n", ch);

    return (0);
}