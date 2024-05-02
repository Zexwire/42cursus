/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:52 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 15:34:43 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Writes a string to a file followed by a newline
/// @param s String to write
/// @param fd File descriptor
void	ft_putendl_fd(char *s, int fd)
{
	char	nwln;

	nwln = '\n';
	write(fd, s, ft_strlen(s) * sizeof(char));
	write(fd, &nwln, sizeof(char));
}
