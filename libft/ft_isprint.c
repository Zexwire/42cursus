/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:39:01 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 14:36:10 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks for a printable character
/// @param c Character to check
/// @return 1 if the character is printable. 0 otherwise
int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}
