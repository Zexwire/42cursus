/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:54:59 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/27 12:27:23 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//FIXME: conseguir quitar los squiggles sin esto
# define BUFFER_SIZE 32
# include <unistd.h>
# include <stdarg.h>

char *get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif