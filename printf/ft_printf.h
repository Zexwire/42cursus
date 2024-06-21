/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:29:47 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/21 21:50:42 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *format, ...);
void	ft_printnbr(int n, int *count);
size_t	ft_strlen(const char *s);
void	ft_printnbr_uns(unsigned long long nbr, char *base, int *count);

#endif