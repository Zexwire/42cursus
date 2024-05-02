/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:45:36 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:34:04 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Writes a character to a file
/// @param c Character to write
/// @param fd File descriptor
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
