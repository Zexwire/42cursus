/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:31:04 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 14:33:58 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks for a character digit (0 through 9)
/// @param c Character to check
/// @return 1 if the character is a digit. 0 otherwise
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
