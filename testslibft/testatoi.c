/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:00:19 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 14:28:21 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void test_ft_atoi(const char *str, int expected_result) {
    int result = ft_atoi(str);
    if (result == expected_result) {
        printf("PASS: ft_atoi(\"%s\") = %d\n", str, result);
    } else {
        printf("FAIL: ft_atoi(\"%s\") = %d, expected %d\n", str, result, expected_result);
    }
}

int main() {
    test_ft_atoi("123", 123);
    test_ft_atoi("-123", -123);
    test_ft_atoi("   123", 123);
    test_ft_atoi("   -123", -123);
    test_ft_atoi("0", 0);
    test_ft_atoi("-0", 0);
    test_ft_atoi("   0", 0);
    test_ft_atoi("   -0", 0);
    test_ft_atoi("2147483647", 2147483647);  // INT_MAX
    test_ft_atoi("-2147483648", -2147483648);  // INT_MIN
    return 0;
}