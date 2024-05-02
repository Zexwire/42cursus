/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:37:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 14:34:46 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks for an ASCII character
/// @param c Character to check
/// @return 1 if the character is an ASCII character. 0 otherwise
int	ft_isascii(int c)
{
	return ('\0' <= c && c <= 127);
}
